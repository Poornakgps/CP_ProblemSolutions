#include <bits/stdc++.h>
using namespace std;



set<int> s,s1;
map<int, int> m;
set<int> :: iterator it,jt;

void compress_and_insert(int n){
	int c=1;
	for(it = s1.begin();it != s1.end();it++){
		s.insert(c);
		m[*it] = c++;
	}
 
}
// https://www.spoj.com/problems/POSTERS/
int main(){
	int n;
	int t;
    cin>>t;
    while(t--){
        cin>>n;
		
		vector<pair<int, int>> v,c;
		v.clear();
		m.clear();
		s1.clear();
		int a,b;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			v.push_back({a,b});
			s1.insert(a);
			s1.insert(b);
		}
		reverse(v.begin(),v.end());
		compress_and_insert(n);
		int ans=0;
		s.insert(1000000007);

		for(int i=0;i<n;i++){
			int a = m[v[i].first];
			int b = m[v[i].second];
			//cout << a << " " << b << endl;
			it = s.lower_bound(a);
			jt = s.upper_bound(b);
			if(it != jt){
				s.erase(it,jt);
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}