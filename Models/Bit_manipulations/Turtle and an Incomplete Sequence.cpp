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

// https://codeforces.com/contest/1981/problem/C

/***************************************C-H-A-O-S**************************************/
int left_one(int n){
    return log2(n);
}

ll count(ll mn, ll mx, ll &mn_lft, ll &mx_lft){  // working

    ll p1 = mn_lft, p2 = mx_lft;
    
    while((mn >> mn_lft) == (mx >> mx_lft) && mn_lft >= 0 && mx_lft >= 0){
        mn_lft--;
        mx_lft--;

    }

    if(mn_lft < 0){
        return mx_lft+1;
    }
    return 2+ mn_lft + mx_lft;
}

void solve(){
    
    ll n;
    cin >> n;
    vi a(n);
    fill(a);

    vi b(n);

    ll last = -1, ind = -1, val = -1;

    for(int i=0; i<n; i++){
        if(a[i]==-1){
            continue;
        }
        b[i] = a[i];
        ll lft = left_one(a[i]);
        if(last == -1){
            last = lft;
            ind = i;
            val = a[i];
            continue;
        }

        if((i-ind)%2 != abs(last-lft)%2){    // case: 1
            cout << "-1\n";
            return;
        }
        ll k1 = min(lft, last), k2 = max(lft, last);
        ll cnt = count(min(val, a[i]), max(val, a[i]), k1, k2);

        if(cnt > i-ind){       // case: 2
            cout << "-1\n";
            return;
        }
        ll c = a[i];
        ll f = 0;
        // Moto: bring min to max
        if(a[i]>val){
            for(int j=ind+1; j<i; j++){
                if(k1>=0){
                    b[j] = val/2;
                    val = val/2;
                    k1--;
                    continue;
                }
                
                if((a[i]>>k2 & 1)){
                    b[j] = val*2 + 1;
                    val = val*2 + 1;
                    k2--;
                }
                else if(k2>=0){
                    b[j] = val*2;
                    val = val*2;
                    k2--;
                }
                else{
                    if(f %2 == 0){
                        b[j] = val*2;
                        val = val*2;
                    }
                    else{
                        b[j] = val/2;
                        val = val/2;
                    }
                    f++;
                }
            }
        }
        else{
            for(int j=i-1; j>ind; j--){
                if(k1>=0){
                    b[j] = a[i]/2;
                    a[i] = a[i]/2;
                    k1--;
                    continue;
                }
                
                if((val>>k2 & 1)){
                    b[j] = a[i]*2 + 1;
                    a[i] = a[i]*2 + 1;
                    k2--;
                }
                else if(k2>=0){
                    b[j] = a[i]*2;
                    a[i] = a[i]*2;
                    k2--;
                }
                else{
                    if(f %2 == 0){
                        b[j] = a[i]*2;
                        a[i] = a[i]*2;
                    }
                    else{
                        b[j] = a[i]/2;
                        a[i] = a[i]/2;
                    }
                    f++;
                }
            }
        }
        last = lft;
        ind = i;
        val = c;
    }
    last = -1;
    for(int i=0; i<n; i++){
        if(b[i]==0 && last != -1){
            if(last*2<=1000000000){
                b[i] = last*2;
                last = last*2;
            }
            else{
                b[i] = last/2;
                last = last/2;
            }
        }
        last = b[i];
    }
    last = -1;
    for(int i=n-1; i>=0; i--){
        if(b[i]==0 && last != -1){
            if(last*2<=1000000000){
                b[i] = last*2;
                last = last*2;
            }
            else{
                b[i] = last/2;
                last = last/2;
            }
        }
        last = b[i];
    }
    last = 1;
    for(int i=0; i<n; i++){
        if(b[i]==0){
            if(last*2<=1000000000){
                b[i] = last*2;
                last = last*2;
            }
            else{
                b[i] = last/2;
                last = last/2;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}