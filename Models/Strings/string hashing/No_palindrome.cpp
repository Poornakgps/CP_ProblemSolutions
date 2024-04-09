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

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return binpow(a, mod_10 - 2, mod_10); }

ll inv_p1[1000002], inv_p2[1000002];

void pre(){
    inv_p1[0] = 1 , inv_p2[0] = 1;
    inv_p1[1] = binpow(31 ,mod_10 - 2, mod_10) , inv_p2[1] = binpow(37 , mod_10, mod_10 + 2);
    for(int i=1;i<1000002;i++){
        inv_p1[i] = inv_p1[1] * inv_p1[i-1] % mod_10;
        inv_p2[i] = inv_p2[1] * inv_p2[i-1] % (mod_10 + 2);
    }
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

struct Hash {
    ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    ll p1 = 31, p2 = 37;
    vector<ll> pow1, pow2;
    vector<ll> hash1, hash2;
    Hash(string s) {
        int n = s.size();
        pow1.resize(n);
        pow2.resize(n);
        hash1.resize(n);
        hash2.resize(n);
        pow1[0] = 1;
        pow2[0] = 1;
        hash1[0] = s[0] - 'a' + 1;
        hash2[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++) {
            pow1[i] = (pow1[i - 1] * p1) % mod1;
            pow2[i] = (pow2[i - 1] * p2) % mod2;
            hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * pow1[i]) % mod1;
            hash2[i] = (hash2[i - 1] + (s[i] - 'a' + 1) * pow2[i]) % mod2;
        }
    }
    pair<ll, ll> get_hash(ll l, ll r) {
        ll hash_value1, hash_value2;
        if (l == 0) {
            hash_value1 = hash1[r];
            hash_value2 = hash2[r];
        } else {
            ll inv_l1 = inv_p1[l]; // modular inverse of pow1[l] under mod1
            ll inv_l2 = inv_p2[l];
            hash_value1 = ((hash1[r] - hash1[l - 1] + mod1) * inv_l1) % mod1;
            hash_value2 = ((hash2[r] - hash2[l - 1] + mod2) * inv_l2) % mod2;
        }
        return {hash_value1, hash_value2};
    }
};

void solve() {


    string s;
    cin >> s;

    ll n = s.size();

    string t = s;

    reverse(all(t));

    Hash prefix(s), suffix(t);

    deque<pii> intervals;

    ll prev = 0;

    for(int i = 0; i < n; i++) {
        ll palindrome_length = (1 + i - prev) / 2;
        ll r = i;
        ll l = prev;
        if(prefix.get_hash(l, l + palindrome_length) != suffix.get_hash(n - r - 1, n - r - 1 + palindrome_length)) { // not palindrome
            prev = i + 1;
            i++;
            intervals.pb({l, r});
        }
    }

    if(!intervals.empty() && !(intervals.back().ss == n - 1)) {
        prev = n-1;
        while(!intervals.empty()) {
            ll l = intervals.back().first;
            ll r = n - 1;
            intervals.pop_back();
            ll palindrome_length = (1 + r - l) / 2;
            if(l==0){
                if(prefix.get_hash(l, l + palindrome_length) != suffix.get_hash(n - r - 1, n - r - 1 + palindrome_length)) { // not palindrome
                    intervals.pb({l, r});
                    break;
                }     
                break;
            }
            ll l_2 = intervals.back().first;
            ll r_2 = intervals.back().ss;
            intervals.pop_back();
            bool flag=0;
            for(int i = r_2 ; i <= prev; i++) {
                ll palindrome_length1 = (1 + i - l_2) / 2;
                ll palindrome_length2 = (1 + r - (l + ( i - r_2))) / 2;
                ll r_new = i;
                ll l_new = l_2;
                if(prefix.get_hash(l_new, l_new + palindrome_length1) != suffix.get_hash(n - r_new - 1, n - r_new - 1 + palindrome_length1) && 
                   prefix.get_hash(l + (i-r_2), l + (i - r_2) + palindrome_length2) != suffix.get_hash(n - r - 1, n - r - 1 + palindrome_length2)) { // not palindrome
                    intervals.pb({l_new, r_new});
                    if(i!=r)
                        intervals.pb({l+(i-r_2), r});
                    flag = 1;
                    break;
                }
            }
            prev = r_2;
            if(flag){
                break;
            }
        }
    }
    if(intervals.empty()) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout<<intervals.size()<<endl;
    for(auto x: intervals) {
        for(int i = x.ff; i <= x.ss; i++) {
            cout << s[i];
        }
        cout << " ";
    }
    endl();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    pre();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
