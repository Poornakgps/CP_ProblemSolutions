#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>;
#define mod_10 100000007
typedef long long ll;
#define mod_9 998244353
#define lmt 1000000000000000000
#define endl() cout << endl


const int MOD = mod_10;
const int MAX = 34000;

int catalan[MAX];

void init() {
    int n = MAX;
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    for(int i=0; i<10; i++) {
        cout<<catalan[i]<<" ";
    }
    endl();

    // analytical formula for nth catalan number
    // C(n) = (2n)! / ((n+1)! * n!)
    return 0;
}