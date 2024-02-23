
/*
in less_equal<int> we cannot erase lower_bound(int) if we try it will erase the next higher element to than int

but it works in less<int>

if you want to erase in multiset then follow this pattern

 int idx= x.order_of_key(int)  -> this is index of that particular number
 delete using x.erase(x.find_by_order(idx));

 ***** using of less_equal lower_bound works as upper_bound and vice-versa.

*/
#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_multiset;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
 
int main() {
	ordered_multiset ms;
    vector<int> v{1, 1, 2, 2, 3, 4, 5, 6, 6};
 
    for(int i : v) ms.insert(i);
 
	cout << "Ordered Multiset: ";
    for(auto x : ms) cout << x << ' '; cout << '\n';
 
    cout << "Lower bound of 2: " << *ms.lower_bound(2) << '\n';
    cout << "Upper bound of 2: " << *ms.upper_bound(2) << '\n';

    int n;
    cin>>n;
    ordered_set st;
    int t=0;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        st.insert({temp,t++});
    }
    for(auto it: st){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    cout<<st.find_by_order(0)<<endl;
    return 0;
}