#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll n,x,y,z;
ll arr[51];
bool done[51][51];
ll dp[51][51][51];

ll rec(ll l,ll r,ll k){
    if(l==r){
        if(k==arr[l]){
            return 0;
        }else return 1e9;
    }
    if(done[l][r])
    return dp[l][r][k];


    for(ll i=0;i<50;i++)dp[l][r][i]=1e9;
    
    for(ll mid=l;mid<r;mid++){
        for(ll val1=0;val1<50;val1++){
            for(ll val2=0;val2<50;val2++){
                dp[l][r][((x*val1+y*val2+z)%50)]=min(dp[l][r][((x*val1+y*val2+z)%50)],rec(l,mid,val1)+rec(mid+1,r,val2)+val1*val2);

            }
        }
    }

    done[l][r]=1;
    return dp[l][r][k];
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    // cin >> t;
    while (t--)
    {
        cin>>n>>x>>y>>z;
        for(ll i=0;i<n;i++)cin>>arr[i];
        ll ans=1e9;
        for(ll i=0;i<50;i++){
            ans=min(ans,rec(0,n-1,i));
        }
        cout<<ans<<'\n';
    }
    return 0;
}