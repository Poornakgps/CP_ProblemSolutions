#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

const int N = 100010;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    ll dist[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = 1e18;
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], 1LL * c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == 1e18) cout << "-1\n";
        else cout << dist[a][b] << "\n";
    }

}