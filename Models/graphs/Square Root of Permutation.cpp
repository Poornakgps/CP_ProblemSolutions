#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout << endl
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

const int N=1e6;
int n,a[N+10];
bool vis[N+10];
int cnt;
vector<int> b[N+10];
int lst[N+10];
int ans[N+10];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			++cnt;
			int p=i;
			while(!vis[p]) vis[p]=true,b[cnt].push_back(p),p=a[p];
		}
	for(int i=1;i<=cnt;i++){
		int len=b[i].size();
		if(len%2!=0){
			int x=0;
			for(int j=1;j<=len;j++)
				if(2*j%len==1%len)
					x=j;
			if(x==0) return cout<<-1,0;
			for(int j=0;j<len;j++) ans[b[i][j]]=b[i][(j+x)%len];
		}
		else{
			if(!lst[len]) lst[len]=i;
			else{
				for(int j=0;j<len;j++) ans[b[lst[len]][j]]=b[i][j];
				for(int j=0;j<len;j++) ans[b[i][j]]=b[lst[len]][(j+1)%len];
				lst[len]=0;
			}
		}
	}
	for(int i=1;i<=n;i++) if(lst[i]) return cout<<-1,0;
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}