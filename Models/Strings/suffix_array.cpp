#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

char s[N];
int n, sa[N], rk[N << 1], old_rk[N << 1], old_sa[N], cnt[N];


// source: https://medium.com/@florian_algo/introduction-to-suffix-array-9080f9f359ce
// Time complexity: O(n(logn))  uses radix sort + binary lifting and double-key sorting

/*
    Radix sort in suffix sorting is essentially sorting a pair of elements (old_sa[i], old_sa[i]+d). 
    It actually performs two counting sorts.   
*/

int main()
{
    int m = 127;
   
    scanf("%s", s + 1);
    n = strlen(s + 1);
   
    // Counting sort of the original array begins
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
   
    for (int i = 1; i <= n; ++i)
       printf("%d ", sa[i]);
   
    return 0;
 }