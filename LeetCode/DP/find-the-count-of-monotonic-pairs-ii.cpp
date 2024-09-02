#include<bits/stdc++.h>

using nmespace std;

#define ll long long

const int mod = 1e9+7;

int dp[2001][1001];
int countOfPairs(vector<int>& nums) {

    for(int i=0; i <=nums[0]; i++){
        dp[0][i] = 1;
    }
    int n = nums.size();
    for(int i=1; i<n; i++){
        int k = 0, ways = 0;
        for(int j = 0; j<=nums[i]; j++){

            if(k<=min(j, j-nums[i]+nums[i-1])){
                ways += (dp[i-1][k]);
                ways = ways%mod;
                k++;
            }
            dp[i][j] = ways;
        }
    }
    int ans = 0;

    for(int i=0; i<=nums[n-1]; i++){
        ans = (ans + dp[n-1][i])%mod;
    }
    return ans;
}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<countOfPairs(arr)<<endl;;
}