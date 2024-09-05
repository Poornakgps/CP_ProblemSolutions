#include<bit/stdc++.h>

using namespace std;

vector<int> g[100005];

int indp[100005];

void in_dfs(int node, int parent = 0){

    // initialize 0 for indp[node] assuming this as leaf node

    indp[node] = 0;

    for(auto it: g[node]){

        if(it== parent) continue;

        in_dfs(it, node);
        indp[node] = max(indp[node], indp[it]+1);
    }
}

int outdp[100005];

void out_dfs(int node, int parent, int outval){

    outdp[node] = outval;

    int mx_child = 0, smx_child = 0;
    // precalculate for top 2
    for(auto it: g[node]){
        if(it == parent) continue;

        if(indp[it]>= indp[mx_child]){
            smx_child = mx_child;
            mx_child = it;

        }
        else if(indp[it] >= indp[smx_child]){
            smx_child = it;
        }
    }

    // calculate for each sibling and pass the value to it
    for(auto it: g[node]){
        if(it == parent) continue;

        int best_sibling = mx_child;

        if(best_sibling == it) best_sibling = smx_child;

        int ch_outval = 1 + outdp[node];

        if(best_sibling!=0){
            ch_outval = max(ch_outval, 1 + 1 + indp[best_sibling]);
        }
        out_dfs(it, node, ch_outval);
    }
}

int ansdp[100005];

void ans_dfs(int node, int parent){
    int mx_child = 0, smx_child = 0;
    // precalculate for top 2
    for(auto it: g[node]){

        if(it == parent) continue;

        ans_dfs(it, node);

        if(indp[it]>= indp[mx_child]){
            smx_child = mx_child;
            mx_child = it;

        }
        else if(indp[it] >= indp[smx_child]){
            smx_child = it;
        }
    }
    int node_ans = indp[nn] + outdp[parent];
    if(smx_child!=0){
        node_ans = max(node_ans, 1 + indp[mx_child] + 1 + indp[smx_child]);
    }
    ans[node] = node_ansl
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    in_dfs(1);
    out_dfs(1, 0, 0);
    ans_dfs(1, 0); 
    for(int i=1; i<=n; i++){
        cout<<ansdp[i]<<" "; // gives u maximum path in tree that consists ith node 
    }
    cout<<endl;
}

