/*Mistakes done:
  push logic should be done carefully
  order of push operations should be like assign first then increase
  
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define endl '\n'
#define mod 1000000007
#define all(x) x.begin(), x.end()

using state = pair<int, int>;
/*
 lazy_type: 
 0: increase 
 1: assign
*/
#define MAXN 2e5 + 1

// struct node{
//     int sum, lazyset, lazysum;
//     node(){
//         sum =  lazyset = lazysum = 0;
//     }
// };
struct node{
    int sum, lazy;
    int lazy_type;
    node(){
        sum =  lazy = lazy_type = 0;
    }
};
vector<int>arr;

node t[4*(int)MAXN]; // array which is seg tree
node merge(node a, node b){
    node temp;
    temp.sum = a.sum + b.sum;
    return temp;
}
void build(int id, int l, int r){
    if(l == r){
        t[id].sum = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2 + 1, mid + 1, r);
    t[id] = merge(t[2*id], t[2*id+1]);
}

void push(int id, int l, int r){
    if(t[id].lazy){
        // cout << "push: " << l << " " << r << " type: " << t[id].lazy_type << endl; 
        if(t[id].lazy_type == 1){//sum
           
            t[id].sum += t[id].lazy*(r-l+1);
            if(l != r){
                t[2*id].lazy += t[id].lazy;
                t[2*id + 1].lazy += t[id].lazy;
                if(t[2*id].lazy_type == 0) t[2*id].lazy_type = 1;
                if(t[2*id + 1].lazy_type == 0) t[2*id + 1].lazy_type = 1;
            }
            
        }
        else if (t[id].lazy_type == 2){//set
             t[id].sum = t[id].lazy*(r-l+1);
             if(l != r){
                t[2*id].lazy = t[id].lazy;
                t[2*id + 1].lazy = t[id].lazy;
                t[2*id].lazy_type = 2;
                t[2*id + 1].lazy_type = 2;
             }
        }
        t[id].lazy = 0;
        t[id].lazy_type = 0;
    }
}
void update(int id, int l, int r, int lq, int rq, int v, int type){
    //whenever you visit the node perform push()
    push(id, l, r);

    if(l > rq || r < lq)return;

    if(lq <= l && r <= rq){
           t[id].lazy = v;
           t[id].lazy_type = type;
        //    cout << "range: " << l << " " << r <<" lazy: " << t[id].lazy << " type: " << t[id].lazy_type << endl; 
           push(id, l, r); // to operate merge logic of ancestors correctly
           return;
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, lq, rq, v, type);
    update(id << 1 | 1, mid + 1, r, lq, rq, v, type);
    t[id] = merge(t[id*2], t[id*2 + 1]); // whenever you are merging two nodes those nodes are clean that is there's no lazy at that nodes

}
node query(int id, int l, int r, int lq, int rq){
       push(id, l, r);
       if(l > rq || r < lq)return node();
       if(lq <= l && r <= rq){
        // cout << "query: " << l << " " << r << endl; 
        return t[id];
       }
       int mid = (l+r) >> 1;
       return merge(query(2*id, l, mid, lq, rq), query(2*id + 1, mid + 1, r, lq, rq));
}

void solve()
{
   int n, q; cin >> n >> q;
   arr.resize(n);
   for(int i = 0; i < n; i++) {
       cin >> arr[i];
   }
   build(1, 0, n-1);

   for(int i = 0; i < q; i++){
        int cur; cin >> cur;
        if(cur == 1){
           int a, b, x; cin >> a >> b >> x;
           update(1, 0, n-1, a-1, b-1, x,cur);
        }
        else if(cur == 2){
             int a, b, x; cin >> a >> b >> x;
             update(1, 0, n-1, a-1, b-1, x, cur);
        }
        else{
            int a, b; cin >> a >> b;
            node x = query(1, 0, n - 1, a-1, b-1);
            cout << x.sum << endl; 
        }
   }
   
}
int32_t main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while (t--){
        solve();
    }
    return 0;
}