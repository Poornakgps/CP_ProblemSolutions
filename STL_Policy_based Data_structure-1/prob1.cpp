#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
// #define ff first 
// #define ss second 

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

// greater<int>(decreasing order) or less<int> (increasing order)
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

int main(){

    auto start= high_resolution_clock::now();

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int sz=0;
    cin>>n;
    vector<int> ans(n,0);
 
    ordered_set t;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        ans[t.order_of_key({x,++sz})]++;
        cout<<t.order_of_key({x,sz-1})<<" ";
        t.insert({x,sz});
    }
    cout<<endl;
 
    for(int i=0;i<n;i++)
        cout<<ans[i]<<'\n';

    auto stop= high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    // cout << "Time taken : "<< (float)(duration.count())/1000 << " milliseconds" << endl;
}