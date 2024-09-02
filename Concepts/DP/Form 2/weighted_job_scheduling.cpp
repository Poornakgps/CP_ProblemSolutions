#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct job{
    int start, end, prize;
};

int main(){
    int n;
    cin>>n;

    vector<ll> dp(n+5, 0);

    vector<job> jobs(n);
    for(int i=0; i<n; i++){
        cin>>jobs[i].start>>jobs[i].end>>jobs[i].prize;
    }
    sort( jobs.begin(), jobs.end(), [](job A, job B) -> bool {
        return A.start < B.start;
    });

    ll ans = 0;
    for(int i=n-1; i>=0; i--){

        int f = -1;
        ll pz = jobs[i].prize;

        ll l = i+1, r = n-1;
        ll mx = 0;
        while(l<=r){
            ll mid = (r-l)/2 + l;

            if(jobs[mid].start>jobs[i].end){
                r = mid-1;
                f = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(f==-1){
            if(i+1<n)
                dp[i] = max(pz, dp[i]);
            else{
                dp[i] = pz;
            }
            ans = max(ans, dp[i]);
            continue;
        }
        dp[i] = max(dp[i], dp[f]+pz);
        ans = max(ans, dp[i]);

        if(i+1<n){
            dp[i] = max(dp[i], dp[i+1]);
        }
        
    }
    cout<<ans<<endl;

    return 0;
}