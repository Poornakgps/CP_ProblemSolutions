#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;

char s[N];
// To prevent accessing rk[i+d] from causing array out of bounds, 
// double the space when declaring.
int n, d, sa[N], rk[N << 1], old_rk[N << 1];

// source: https://medium.com/@florian_algo/introduction-to-suffix-array-9080f9f359ce

// Time complexity: O(n(logn)^2) uses stl sort + binary lifting and double-key sorting
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        sa[i] = i, rk[i] = s[i];

    for (d = 1; d < n; d <<= 1)
    {
        // sort two keys using C++ lambda function
        sort(sa + 1, sa + n + 1, [](int x, int y)
             { return rk[x] == rk[y] ? rk[x + d] < rk[y + d] : rk[x] < rk[y]; });
        
        memcpy(old_rk, rk, sizeof(rk));

        // The purpose of this loop is to update the ranking.
        for (int rank = 0, i = 1; i <= n; ++i)
        {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] &&
                old_rk[sa[i] + d] == old_rk[sa[i - 1] + d])
                rk[sa[i]] = rank;
            else
                rk[sa[i]] = ++rank; 
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", sa[i]);

    return 0;
}