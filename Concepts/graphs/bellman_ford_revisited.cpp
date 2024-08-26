#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int md = 1e9 + 7;

struct Edge{
    int u, v, w;
};


int main(){

    int n, m;
    cin >> n >> m;

    Edge E[m];
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        E[i].u = a;
        E[i].v = b;
        E[i].w = -c;
    }

    ll dist[n+1];
    for(int i=1; i<=n; i++){
        dist[i] = 1e18;
    }
    dist[1] = 0;

    for(int i=1; i<=n; i++){

        for(int j=0; j<m; j++){

            ll a, b, c;
            a = E[j].u, b = E[j].v, c = E[j].w;

            dist[b] = min(dist[b], dist[a]+c);
        }
    }

    bool neg = false;


    for(int i=0; i<m; i++){
        ll a, b, c;
        a = E[j].u, b = E[j].v, c = E[j].w;

        if(dist[b]> dist[a]+ c){
            neg = false;
            break;
        }
    }
    if(neg) cout<<-1<<endl;
    else{
        assert(dist[n]!=1e18);
        cout<<-dist[n]<<endl;
    }

}