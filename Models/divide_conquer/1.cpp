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
#define  MAXN 200005
#define N_LMT 2000005

/***************************************C-H-A-O-S**************************************/
class AdjacentSwapToSortArray {
public:
    int minimum_adjacent_swaps_to_sort_array(vector<int>& input_arr) {
        cerr << "Input[]: ";
        for (int val : input_arr) {
            cerr << val << " ";
        }
        cerr << endl;
        
        int total_inversions = divide(input_arr, 0, input_arr.size() - 1);
        cerr << "Minimum adjacent swaps required to sort the array: " << total_inversions << endl;
        return total_inversions;
    }

private:
    int divide(vector<int>& input_arr, int low, int high) {
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;

        int left_swaps = divide(input_arr, low, mid);
        int right_swaps = divide(input_arr, mid + 1, high);
        int merge_swaps = conquer_and_count(input_arr, low, mid, high);

        return left_swaps + right_swaps + merge_swaps;
    }

    int conquer_and_count(vector<int>& input_arr, int left_index, int mid_index, int right_index) {
        vector<int> left(input_arr.begin() + left_index, input_arr.begin() + mid_index + 1);
        vector<int> right(input_arr.begin() + mid_index + 1, input_arr.begin() + right_index + 1);

        int i = 0, j = 0, k = left_index, inversions = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                input_arr[k] = left[i];
                i++;
            } else {
                input_arr[k] = right[j];
                j++;
                inversions += (mid_index + 1) - (left_index + i);
            }
            k++;
        }

        while (i < left.size()) {
            input_arr[k] = left[i];
            i++;
            k++;
        }

        while (j < right.size()) {
            input_arr[k] = right[j];
            j++;
            k++;
        }

        return inversions;
    }
};

void solve() {
    
    ll n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    rep(i, 0, n, 1) {
        cin >> a[i];
        mp[a[i]]++;
    }

    AdjacentSwapToSortArray obj;
    int res1 = obj.minimum_adjacent_swaps_to_sort_array(a);
    vector<int> b(n);
    rep(i, 0, n, 1) {
        cin >> b[i];
        mp[b[i]]--;
    }
    for(auto i: mp){
        if(i.ss){
            cout << "NO\n";
            return;
        }
    }
    if(res1%2){
        swap(b[n-1], b[n-2]);
    }
    int res2 = obj.minimum_adjacent_swaps_to_sort_array(b);
    
    if(res2%2){
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
