#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

char s[N];
int n, sa[N], lcp[N], rk[N << 1], old_rk[N << 1], old_sa[N], cnt[N];

void get_sa()
{
    int m = 127;

    // Counting sort of the original array begins
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i)
        ++cnt[rk[i] = s[i]]; 
    for (int i = 1; i <= m; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; --i)
        sa[cnt[rk[i]]--] = i; 

    for (int d = 1; d < n; d <<= 1, m = n)
    {
        // Optimized sort on the second key
        int rank = 0;
        memcpy(old_sa + 1, sa + 1, n * sizeof(int));
        for (int i = n - d + 1; i <= n; i++)
            sa[++rank] = i;

        for (int i = 1; i <= n; i++)
            if (old_sa[i] > d)
                sa[++rank] = old_sa[i] - d;

        // Start counting sort on the first key: old_sa[i]
        memset(cnt, 0, sizeof(cnt));
        memcpy(old_sa + 1, sa + 1, n * sizeof(int));
        for (int i = 1; i <= n; ++i)
            ++cnt[rk[old_sa[i]]];
        for (int i = 1; i <= m; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; --i)
            sa[cnt[rk[old_sa[i]]]--] = old_sa[i];

        // Start updating rankings
        memcpy(old_rk + 1, rk + 1, n * sizeof(int));
        rank = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] &&
                old_rk[sa[i] + d] == old_rk[sa[i - 1] + d])
                rk[sa[i]] = rank;
            else
                rk[sa[i]] = ++rank;
        }

        if (rank == n)
            break;
    }
}
    
void get_lcp()
{
    int k = 0;

    for (int i = 1; i <= n; i++)
        rk[sa[i]] = i;

    for(int i = 1; i <= n; i++)
    {
        if (rk[i] == 1)
            continue;
        if (k)
            k--;
        int j = sa[rk[i] - 1];
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k])
            k++;
        lcp[rk[i]] = k;
    }
}

class Solution {
public:
    string longestDupSubstring(string ss) {
        n = (int)ss.size();
        for(int i = 1; i <= n; i++)
            s[i] = ss[i-1];

        get_sa();
        get_lcp();

        // find longest common prefix between two adjacent suffixes
        int mx = 0;
        for(int i = 1; i <= n; i++)
            if (lcp[i] > lcp[mx])
                mx = i;     
        
        string res;
        for(int i = sa[mx]; i <= sa[mx] + lcp[mx] - 1; i++)
            res += s[i];
        return res;
    }
};

// Problem Description: Given a string, find the longest substring that appears at least twice.

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestDupSubstring(s) << endl;
}