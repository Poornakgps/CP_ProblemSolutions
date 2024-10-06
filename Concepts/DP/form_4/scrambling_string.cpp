#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007


string s1,s2;
int dp[41][41][41];
bool rec(int l,int r,int i){
    int j=i+r-l;
    if(l>r || i>j){
        return false;
    }
    if(l==r){
        return (s1[l]==s2[i]);
    }
    if(dp[l][r][i]!=-1)
    return dp[l][r][i];

    bool ans=0;

    if(s1.substr(l,r-l+1)==s2.substr(i,j-i+1))
    {
        ans=1;
    }else{
        for(int k=l;k<r;k++){
            ans|= (rec(l,k,i)&rec(k+1,r,i+(k-l+1))); // without swapping

            ans|=(rec(l,k,j-(k-l))&rec(k+1,r,i)); // with swapping
        }
    }

    return dp[l][r][i]=ans;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin>>s1>>s2;
        memset(dp,-1,sizeof(dp));
        int n=s1.length();

        if(rec(0,n,0))
        cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    return 0;
}