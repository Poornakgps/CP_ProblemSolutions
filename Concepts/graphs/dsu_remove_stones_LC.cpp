#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<int, int>
typedef long long ll;
#define vi vector<ll>
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 300005
#define N_LMT 100001

/***************************************C-H-A-O-S**************************************/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(20002);  // Initialize UnionFind with a large enough range
                              // to handle coordinates

        // Union stones that share the same row or column
        for (int i = 0; i < n; i++) {
            uf.unionNodes(
                stones[i][0],
                stones[i][1] + 10001);  // Offset y-coordinates to avoid
                                        // conflict with x-coordinates
        }

        return n - uf.componentCount;
    }

private:
    // Union-Find data structure for tracking connected components
    class UnionFind {
    public:
        vector<int> parent;  // Array to track the parent of each node
        int componentCount;  // Number of connected components
        unordered_set<int> uniqueNodes;  // Set to track unique nodes

        UnionFind(int n) {
            parent.resize(n, -1);  // Initialize all nodes as their own parent
            componentCount = 0;
        }

        // Find the root of a node with path compression
        int find(int node) {
            // If node is not marked, increase the component count
            if (uniqueNodes.find(node) == uniqueNodes.end()) {
                componentCount++;
                uniqueNodes.insert(node);
            }

            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void unionNodes(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;  // If they are already in the same component, do
                         // nothing
            }

            // Merge the components and reduce the component count
            parent[root1] = root2;
            componentCount--;
        }
    };
};

void solve() {

    ll n;
    cin>>n;
    vector<vector<int>> stones;
    int unique;
    unique = n;
    for(int i=0; i<n; i++){
        ll x, y;
        cin>>x>>y;

        stones.push_back({x, y});
    }

    ll ans = removeStones(stones, unique);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}