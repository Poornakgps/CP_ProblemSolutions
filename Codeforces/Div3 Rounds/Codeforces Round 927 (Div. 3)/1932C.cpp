#include <bits/stdc++.h>
 
using namespace std;
 

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    string s;
    cin >> s;

    int l = 0;
    int r = n - 1;
    for(int i=0; i<n-1; i++){
        if (s[i] == 'L')
            l++;
        else
            r--;
    }

    vector<int> b(n);
    b[n - 1] = a[l] % m;

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'L')
            b[i] = (b[i + 1] * a[--l]) % m;
        else
            b[i] = (b[i + 1] * a[++r]) % m;
    }

    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;

}
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}