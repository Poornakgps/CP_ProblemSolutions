#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pr(...) {}
struct Coordinate_compression{

    map<int, int> mp;
    vector<int> v;
    int cnt = 0;
    void add(int x){
        mp[x];
    }

    void build(){
        cnt = 0;
        for(auto &it: mp){
            v.emplace_back(it.first);
            it.second = cnt++;
        }
    }
    inline int getComp(int x){
        return mp[x];
    }
    inline int getOriginal(int x){
        return v[x];
    }
    int getPrev(int x){
        auto it = mp.upper_bound(x);
        it--;
        return it->second;
    }
    int getNext(int x){
        auto it = mp.lower_bound(x);
        return it->second;
    }

    void deb(){
        cout<<"HY\n";
        pr(mp);
        pr(v);
    }
}CMP;

void solve(){
    vector<int> arr = {1, 3, 5, 4, 5, 2, 3, 1, 100000000};

    for(auto it: arr){
        CMP.add(it);
    }
    CMP.deb();
    CMP.build();
    CMP.deb();
}

signed main(){
    ios_base::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}