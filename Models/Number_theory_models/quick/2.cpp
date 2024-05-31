#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<int, int>
typedef long long ll;
#define vi vector<ll>
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 200005

/***************************************C-H-A-O-S**************************************/
 
// https://codeforces.com/contest/1349/problem/A
void solve(){

    ll n;
    cin >> n;
    vi v(n);
    fill(v);
    vector<ll> primes[200005];
    set<ll> in;

    for(int i=0; i<n; i++){
        ll x = v[i];
        ll t = v[i];
        for(int j=2; j*j<=t; j++){
            if(x%j==0){
                in.insert(j);
                ll p = 0;
                while(x%j==0){
                    x/=j;
                    p++;
                }
                primes[j].pb(p);
            }
        }
        if(x>1){
            in.insert(x);
            primes[x].pb(1);
        }
    }

    for(int i=1; i<=200000; i++){
        sort(all(primes[i]));
    }

    ll ans = 1, cnt = 0;
    for(auto it: in){
       if(primes[it].size()==n-1){
            ans = ans*(pow(it,primes[it][0]));
       }
       else if(primes[it].size()==n){
            ans = ans*(pow(it,primes[it][1]));
       }
    }
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// alternative approach
/*
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

const int maxn=100005;

int n;
ll a[maxn];

ll pre[maxn],suf[maxn];

ll gcd(ll x, ll y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

ll ga,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	pre[1]=a[1]; suf[n]=a[n];
	for(int i=2;i<=n;i++)
		pre[i]=gcd(pre[i-1],a[i]);
	for(int i=n-1;i>=1;i--)
		suf[i]=gcd(suf[i+1],a[i]);
	for(int i=0;i<=n-1;i++)
	{
		if(i==0)
			ans=suf[2];
		else if(i==n-1)
			ans=ans*pre[n-1]/gcd(pre[n-1],ans);
		else
			ans=ans*gcd(pre[i],suf[i+2])/gcd(gcd(pre[i],suf[i+2]),ans);
	}
	printf("%lld\n",ans);
	return 0;
}
*/