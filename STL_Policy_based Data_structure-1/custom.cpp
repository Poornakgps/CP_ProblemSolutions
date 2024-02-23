#include <cassert>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
 
using namespace std;
using namespace __gnu_pbds;


// tree<int, null_type, function<bool(int, int)>> y([](int a, int b) {
//                                                  return a < b;});

int main(){

    int n;
    cin>>n;
    auto cmp = [](int a, int b){return a < b;};
    tree<int, null_type, decltype(cmp)> x(cmp);

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        x.insert(temp);
    }
    for(auto it: x){
        cout<<it<<" ";
    }
    cout<<endl;
}