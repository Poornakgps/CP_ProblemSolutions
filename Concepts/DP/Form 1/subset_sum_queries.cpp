#include <bits/stdc++.h>
using namespace std;


#define ll int64_t


vector<vector<int>> dp;//  it stores the vector of integers at each level whose sum is equal to the sumleft
ll q,n;
vector<int> v;
int rec(int level,int sum_left){
    int ans;
    if(sum_left<0)return 0;
    //base case
    if(level==n){
        if(sum_left==0){
            return 1;
        }  
        return 0;
    }
    //caching
    if(dp[level][sum_left]!=-1)return dp[level][sum_left];
    //transitions
    ans=rec(level+1,sum_left);//not taken
    if(!ans&&sum_left>=v[level]){
        ans=rec(level+1,sum_left-v[level]);
    }
    //save and return
    return dp[level][sum_left]=ans;
}


vector<int> subset(int level,int sum_left){
    vector<int> ans;
    if(rec(level,sum_left)){
        while(sum_left>0&&level<n){
            if(rec(level+1,sum_left-v[level])){
                ans.push_back(level);
                sum_left-=v[level];
            }
            level++;
        }
    }
    else{
        ans.push_back(-1);
    }
    return ans;
}



vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    vector<vector<int>> sol;

    n=arr.size();
    q=queries.size();
    dp.resize(n+1,vector<int>(1e5+1,-1));
    
    v=arr;
    vector<int> empty_vec;
    empty_vec.push_back(-1);
    for(auto i:queries){
        vector<int> curr_sol=subset(0,i);
        sol.push_back(curr_sol);
    }
    // cout<<queries.size()<<" "<<sol.size()<<endl;



    return sol;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
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