#include <iostream>
#include <algorithm>
#define MOD 998244353

using namespace std;

// Function to handle modular arithmetic
long long mod(long long x) {
    return (x % MOD + MOD) % MOD;
}

long long computeDays(long long W, long long G, long long L) {

    long long totalDistance = (W - G)%MOD;
    
    long long fluctuationRange =(2*L + 1)%MOD;

    long long result = mod(totalDistance * fluctuationRange);

    return result;
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    for (int t = 1; t <= T; ++t) {
        long long W, G, L;
        cin >> W >> G >> L;

        long long result = computeDays(W, G, L);
        
        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
