#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> vis, tin, low, arc, extra;
vector<vector<int>> g;

int timer=1;
int totalcomponent = 0;

void dfs(int v, int p){
    vis[v] = 1;

    tin[v]=low[v] = timer++;
    int children = 0;
    vector<int> chnodes;
    for(auto to: g[v]){

        if(to == p) continue;

        if(vis[to]){
            // backedge
            low[v] = min(low[v], tin[to]);
        }
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            chnodes.push_back(to);
            if(low[to]>=tin[v]){
                arc[v] = 1;
            }
            children++;
        }
    }
    if(p == -1){ // root
        extra[v] = children - 1;
    }
    else{
        // mid node
        for(auto to: chnodes){
            if(low[to]>=tin[v]){
                // this to child leads to a new comp after removing
                extra[v]++;
            }
        }
    }
}

int main(){

    cin>>n>>m;
    g.resize(n+1);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u>> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vis.assign(n+1, 0);
    tin.assign(n+1, 0);
    low.assign(n+1, 0);
    arc.assign(n+1, 0);
    extra.assign(n+1, 0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            totalcomponent++;
            dfs(i, -1);
        }
    }
    for(int i=1; i<=n; i++){
        cout<<i<<" : "<< totalcomponent + extra[i]<<endl;
    }
}