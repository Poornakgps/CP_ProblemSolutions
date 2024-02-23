#include "../../template.h"
#define No() cout<<"No\n"
#define Yes() cout<<"Yes\n"

void solve(){
    ll n;
    cin>>n;
	ll sum = 0;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%n){
        No();
        return;
    }

	sum /= n;
	vector<ll> bit(31, 0), s1(31, 0), s2(31, 0);
	for (int i=0; i<n; i++) {
		bool flag = 0;
		if(arr[i] == sum) 
            continue;
		for (int j=0; j<31; j++) {
            if(arr[i]+(1<<j)==sum){
                s1[j]++;
                flag=1;
                break;
            }
            if(arr[i]-(1<<j)==sum){
                s2[j]++;
                flag=1;
                break;
            }
		}
		if(flag) continue;
		for(int j=0; j<31; j++){
			for (int k=0; k<31; k++) {
			    if (arr[i]+(1<<j)-(1<<k) == sum) {
			        flag=1;
			        bit[j]++;
			        bit[k]--;
			    }
			}
		}
		if(!flag){
            No();
			return;
		}
	}
    for(int i=30; i>=0; i--){
        bit[i]+=(s1[i]-s2[i]);
        if(i==0) break;
        if(bit[i]<0){
            s1[i-1] -= -bit[i];
            bit[i-1] -= -bit[i];
            if(s1[i-1]<0){
                No();
                return;
            }
        }
        else{
            s2[i-1] -= bit[i];
            bit[i-1] += bit[i];
            if(pow2[i-1]<0){
                No();
                return;
            }
        }
    }
    if(!bit[0]){
        Yes();
        return;
    }
    No();
}

int main() {

    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}