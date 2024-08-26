#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

/*
We can scramble a string s to get a string t using the following algorithm:
If the length of the string is 1, stop.If the length of the string is >1, do the following: 2.1 Split the string into two non-empty substrings at a random index, i.e., if the string is 
s, divide it to x and y where s=x+y. 2.2 Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s=x+y or s=y+x.Apply step 1 recursively on each of the two substrings 
x and y.
*/

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
            ans|= (rec(l,k,i)&rec(k+1,r,i+(k-l+1)));

            ans|=(rec(l,k,j-(k-l))&rec(k+1,r,i));
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