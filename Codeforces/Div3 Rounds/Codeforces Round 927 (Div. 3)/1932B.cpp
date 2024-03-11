#include <bits/stdc++.h>
 
using namespace std;


void solve(){
    int n, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int curr=0;
    for (int i=0; i<n; i++){
        curr +=(a[i]- curr%a[i]);
    }
    cout<<curr<<endl;
}
int main() {
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}