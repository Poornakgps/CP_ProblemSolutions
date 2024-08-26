#include<bits/stdc++.h>

using namespace std;

int n;
int x[105], y[105];
int dp[101][101];
int path[101][101];

int recursive(int i, int j){
    if(i>=j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 1e9;

    for(int k=i; k<j; k++){
        int temp = recursive(i, k) + recursive(k+1, j) + x[i]*y[k]*y[j];
        if(ans>temp){
            path[i][j] = k;
            ans = temp;
        }
    }

    return dp[i][j] = ans;
}

int opb[101], clb[101];

void generate(int i, int j){
    if(i==j){
        cout<<"A"<<i;
        return;
    }
    opb[i]++;
    clb[j]++;

    cout<<"(";
    generate(i, path[i][j]);
    cout<<" x ";
    generate(path[i][j]+1, j);
    cout<<")";
}

void solve(){

    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];
    }

    memset(dp, -1, sizeof(dp));

    cout<<recursive(1, n)<<endl;

    generate(1, n);
}

int main(){
    int t = 1;
    cin>>t;

    while(t--){
        solve();
    }
}