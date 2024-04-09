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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    s = s + s;

    Hash hs(s);

    ll m;
    cin >> m;

    unordered_map<pair<ll, ll>, ll, pair_hash> mp;

    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        ll hash_value1 = 0;
        ll hash_value2 = 0;
        for (int i = 0; i < t.size(); i++) {
            hash_value1 = (hash_value1 + (t[i] - 'a' + 1) * hs.pow1[i]) % hs.mod1;
            hash_value2 = (hash_value2 + (t[i] - 'a' + 1) * hs.pow2[i]) % hs.mod2;
        }
        mp[{hash_value1, hash_value2}] = i + 1;
    }

    for (int i = 1; i <= k; i++){
        bool flag = true;
        map<ll, ll> m1, m2;
        vector<ll> ans;
        for (int j = 0; j < n; j++){
            pair<ll, ll> hash_value = hs.get_hash(j * k + i, j * k + i + k - 1);
            if (!mp[{hash_value.ff, hash_value.ss}] || ((m1[hash_value.ff]) && (m2[hash_value.ss]))){
                flag = false;
                break;
            }
            ans.pb(mp[{hash_value.ff, hash_value.ss}]);
            m1[hash_value.ff] = 1, m2[hash_value.ss] = 1;
        }
        if (flag){
            cout << "YES" << endl;
            for (auto u : ans)
                cout << u << ' ';
            return;
        }
    }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    pre();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
