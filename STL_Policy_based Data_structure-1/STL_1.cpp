//STL: Policy based datastructures  https://codeforces.com/blog/entry/11080

//order statistics tree
#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
/*
template<
    typename Key, // Key type
    typename Mapped, // Mapped-policy
    typename Cmp_Fn = less<Key>, // Key comparison functor
    typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
    template<
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_
    >
    class Node_Update = null_node_update, // A policy for updating node invariants
    typename Allocator = allocator<char> 
> // An allocator type
class tree;
*/

/*
the first two types looks like map container this container can be set if we set second to null_type

Tag- denoting a tree datastructure rb_tree is red-black tree and we have other types called 
ov_tree(ordered vector tree) and splay_tree(splay tree)

Node_Update — class denoting policy for updating node invariants. 
By default it is set to null_node_update, ie, additional information 
not stored in the vertices. In addition, C++ implemented an update policy 
tree_order_statistics_node_update, which, in fact, carries the necessary operations.
*/

typedef tree<
int,
null_type,
less<int>,   // greater<int>(decreasing order) or less<int> (increasing order) 
                // using less_equat<int> makes multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

/*
'''
If we want to get map but not the set, as the second argument type must be used 
mapped type. Apparently, the tree supports the same operations as the set but also there are two new 
features — it is find_by_order() and order_of_key().
'''
*/
int main(){

    auto start= high_resolution_clock::now();

    ordered_set x;
    
    x.insert(1);
    x.insert(19);
    x.insert(3);
    x.insert(3); // inserts unique elements
    x.insert(4);
    x.insert(5);
    x.insert(10);
    x.insert(7);
    x.insert(9);

    cout<<"x.find_by_order returns k-th largest element (counting from zero)";

    cout<<*x.find_by_order(1)<<endl;
    cout<<*x.find_by_order(2)<<endl;
    cout<<*x.find_by_order(3)<<endl;
    cout<<(end(x)==x.find_by_order(8))<<endl; // true

    cout<<endl;

    cout<<"order_of_key returns number of elements less than given number\n"; // for less<int>
    // for greater<int>  it works number of elements greater than given number
    cout<<x.order_of_key(-5)<<endl;  
    cout<<x.order_of_key(1)<<endl;   
    cout<<x.order_of_key(3)<<endl;  
    cout<<x.order_of_key(4)<<endl;   
    cout<<x.order_of_key(400)<<endl; 

    auto stop= high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken : "<< (float)(duration.count())/1000 << " milliseconds" << endl;
}

