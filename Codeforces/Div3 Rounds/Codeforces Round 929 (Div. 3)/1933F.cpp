#include"../../../template.h"

void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[n][m], dp[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>a[i][j];
            dp[i][j]=-1;
        }
    }
    deque<pair<ll,ll>> que;
    dp[0][0] = 0;
    que.push_back({0,0});
    while (!que.empty()){
        auto pos = que.front(); 
        que.pop_front();
        ll time = dp[pos.ff][pos.ss];
        if (a[(pos.ff + 1 + time) % n][pos.ss]==0 && a[(pos.ff + 2 + time) % n][pos.ss]==0 && dp[(pos.ff + 1) % n][pos.ss] == -1) {
            que.push_back({(pos.ff+1)%n, pos.ss});
            dp[(pos.ff + 1) % n][pos.ss] = time+1;
        }
        if (pos.ss != m-1 && a[(pos.ff + 1 + time) % n][pos.ss+1]==0 && dp[pos.ff][pos.ss+1] == -1){
            que.push_back({pos.ff, pos.ss+1});
            dp[pos.ff][pos.ss + 1] = time+1;
        }
    }
    ll ans=1e9;
    for (int i=0; i<n; i++){
        if (dp[i][m-1] != -1){
            ans =  min({ans, dp[i][m-1]+i+1 , dp[i][m-1]+n-i-1});
        }
    }
    if(ans==1e9){
        cout<<-1<<"\n";
        return;
    }
    cout<<ans<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}