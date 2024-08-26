#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100010;

int mod = 1e9 + 7;

vector<int> graph[N];
int par[N];

bool dfs(int u, int x)
{
    if (par[u] != -1)
        return par[u] == x;
    par[u] = x;
    for (int v : graph[u])
    {
        if (!dfs(v, 1 - x))
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (par[i] == -1 && !dfs(i, 0))
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
