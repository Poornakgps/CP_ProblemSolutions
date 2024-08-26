#include <bits/stdc++.h>
using namespace std;

// kadane's algorithm and dimension reduction

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		int grid[n][m];

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> grid[i][j];
			}
		}

		long long ans = -2e18;

		if (n >= m)
		{
			for (int l = 0; l < m; ++l)
			{
				long long temp[n];
				bool allNeg = true;
				long long num = -2e18;

				memset(temp, 0, sizeof(temp));

				for (int r = l; r < m; ++r)
				{
					for (int k = 0; k < n; ++k)
					{
						temp[k] += grid[k][r];
						num = max(num, 1LL * grid[k][r]);

						if (grid[k][r] >= 0)
						{
							allNeg = false;
						}
					}

					if (allNeg)
					{
						ans = max(ans, num);
					}
					else
					{
						long long maxSum = temp[0], curSum = 0;

						for (int k = 0; k < n; ++k)
						{
							curSum += temp[k];
							maxSum = max(maxSum, curSum);
							curSum = max(0ll, curSum);
						}

						ans = max(ans, maxSum);
					}
				}
			}
		}
		else
		{
			for (int l = 0; l < n; ++l)
			{
				long long temp[m];
				bool allNeg = true;
				long long num = -2e18;

				memset(temp, 0, sizeof(temp));

				for (int r = l; r < n; ++r)
				{
					for (int k = 0; k < m; ++k)
					{
						temp[k] += grid[r][k];
						num = max(num, 1LL * grid[r][k]);

						if (grid[r][k] >= 0)
						{
							allNeg = false;
						}
					}
					if (allNeg)
					{
						ans = max(ans, num);
					}
					else
					{
						long long maxSum = temp[0], curSum = 0;

						for (int k = 0; k < m; ++k)
						{
							curSum += temp[k];
							maxSum = max(maxSum, curSum);
							curSum = max(0ll, curSum);
						}
						
						ans = max(ans, maxSum);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
