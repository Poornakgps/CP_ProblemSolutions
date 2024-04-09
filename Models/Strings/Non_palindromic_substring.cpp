#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pr;
ll mod = 1e9 + 7;
int N = 200005;

vector<ll> a1(N, 0);
vector<ll> a2(N, 0);
vector<ll> b1(4 * N, 0);
vector<ll> b2(4 * N, 0);
vector<ll> orbs(N + 1);

// Generate random base in (before, after) open interval:
int gen_base(const int before, const int after)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<int>(before + 1, after)(mt_rand);
    return base % 2 == 0 ? base - 1 : base;
}

struct PolyHash
{
    // -------- Static variables --------
    static const int mod1 = (int)1e9 + 7; // prime mod of polynomial hashing
    static const int mod2 = (int)1e9 + 9; // prime mod of polynomial hashing

    /*
        y 2 values?
        because we need to use 2 different mod values to avoid collisions while comparing two hashes 
    */
    static std::vector<int> pow1; // powers of base modulo mod
    static std::vector<int> pow2; // powers of base modulo
    static int base1;             // base (point of hashing)
    static int base2;             // base (point of hashing)

    // -------------- Variables of class -------------
    std::vector<int> pref1; // Hash on prefix modulo mod
    std::vector<int> pref2; // Hash on prefix modulo 2^64

    // Cunstructor from string:
    PolyHash(const std::string &s)
        : pref1(s.size() + 1, 0), pref2(s.size() + 1, 0)
    {
        assert(base1 < mod1);
        assert(base2 < mod2);

        const int n = s.size(); // Firstly calculated needed power of base:
        while ((int)pow1.size() <= n)
        {
            pow1.push_back(1LL * pow1.back() * base1 % mod1);
            pow2.push_back(1LL * pow2.back() * base2 % mod2);
        }
        for (int i = 0; i < n; ++i)
        { // Fill arrays with polynomial hashes on prefix
            assert(base1 > s[i]);
            assert(base2 > s[i]);

            pref1[i + 1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod1;
            pref2[i + 1] = (pref2[i] + 1LL * s[i] * pow2[i]) % mod2;
        }
    }

    // Polynomial hash of subsequence [pos, pos+len)
    // If mxPow != 0, value automatically multiply on base in needed power. Finally base ^ mxPow
    inline std::pair<int, int> operator()(const int pos, const int len, const int mxPow = 0) const
    {
        int hash1 = pref1[pos + len] - pref1[pos];
        int hash2 = pref2[pos + len] - pref2[pos];
        if (hash1 < 0)
            hash1 += mod1;
        if (hash2 < 0)
            hash2 += mod2;
        if (mxPow != 0)
        {
            hash1 = 1LL * hash1 * pow1[mxPow - (pos + len - 1)] % mod1;
            hash2 = 1LL * hash2 * pow2[mxPow - (pos + len - 1)] % mod2;
        }
        return std::make_pair(hash1, hash2);
    }
};

// Init static variables of PolyHash class:
int PolyHash::base1((int)1e9 + 7);
int PolyHash::base2((int)1e9 + 9);

std::vector<int> PolyHash::pow1{1};
std::vector<int> PolyHash::pow2{1};

void solve()
{
    ll n, m = -1, x = 0, y = 0, z, k, q;
    string s, s1, s2;
    cin >> n >> q;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());

    const int mxPow = n;
   
    PolyHash hash_a(s), hash_b(t);
    vector<vector<ll>> ps(n + 1, vector<ll>(26, 0));
    vector<vector<ll>> od(n + 1, vector<ll>(26, 0));
    vector<vector<ll>> ev(n + 1, vector<ll>(26, 0));
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            ps[i][j] += ps[i - 1][j];
            od[i][j] += od[i - 1][j];
            ev[i][j] += ev[i - 1][j];
        }
        ps[i][s[i - 1] - 97]++;
        if (i % 2 == 0)
            ev[i][s[i - 1] - 97]++;
        else
            od[i][s[i - 1] - 97]++;
    }

    for (int i = 1; i <= q; i++)
    {
        ll tell1 = 0, tell2 = 0, tell3 = 0, tell4 = 0;
        ll l, r;
        cin >> l >> r;
        ll len = (r - l) + 1;
        ll even = len / 2, odd = len / 2;
        ll ans = (len * (len + 1)) / 2;
        if (len % 2 != 0)
        {
            if (l % 2 != 0)
                odd++;
            else
                even++;
        }
        for (int j = 0; j < 26; j++)
        {
            if (ps[r][j] - ps[l - 1][j] == len)
                tell1 = 1;
            if (ev[r][j] - ev[l - 1][j] == even)
                tell2 = 1;
            if (od[r][j] - od[l - 1][j] == odd)
                tell3 = 1;
        }

        auto gen1 = hash_a(l - 1, len, mxPow);
        int st = n - r;
        auto gen2 = hash_b(st, len, mxPow);

        if (gen1 == gen2)
            tell4 = 1;

        if (tell1) // all are same characters in the substring
        {
            ans = 0;
        }
        else if (tell2 && tell3)   //  if they are alternative characters all are same
        {
            ll mn = (len + 1) / 2;
            ans = ans - mn * mn;
        }
        else if (tell4)     // if the substring is palindrome
        {
            ans = ans - (len + 1);
        }
        else   // if the substring is not palindrome
        {
            ans = ans - 1;
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    PolyHash::base1 = gen_base(256, PolyHash::mod1);
    PolyHash::base2 = gen_base(256, PolyHash::mod2);
    ll t;
    t = 1;

    cin >> t;
    while (t--)
    {
        solve();
    }
}