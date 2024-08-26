#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n, m;
vector<vector<int>> adj;
void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    vector<int> out_deg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u); // reverse edge.
        out_deg[u]++;        // out-degree
    }
    int t = n;
    vector<int> ans(n + 1);
    priority_queue<int> pq; // labelling higher node with higher label.
    for (int i = 1; i <= n; i++)
        if (out_deg[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        int v = pq.top();
        pq.pop();
        ans[v] = t--; // labelling from n to 1.( decreasing order )
        for (auto x : adj[v])
        {
            out_deg[x]--;
            if (out_deg[x] == 0)
                pq.push(x);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}