#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};
void solve() {
    cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cin >> grid[i][j];
    }
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, 1e9));
    deque<array<int, 2>> dq;
    dq.push_front({0, 0});
    dist[0][0] = 0;
    while (!dq.empty()) {
        auto v = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + v[0], y = dy[i] + v[1];
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] == '.') {
                    if (dist[x][y] > dist[v[0]][v[1]]) {
                        dist[x][y] = dist[v[0]][v[1]];
                        dq.push_front({x, y});
                    }
                }
                else {
                    for (int p = x - 1; p <= x + 1; p++) {
                        for (int q = y - 1; q <= y + 1; q++) {
                            if (p >= 0 && p < n && q >= 0 && q < m) {
                                if (dist[p][q] > dist[v[0]][v[1]] + 1) {
                                    dist[p][q] = dist[v[0]][v[1]] + 1;
                                    dq.push_back({p, q});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dist[n - 1][m - 1];
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}