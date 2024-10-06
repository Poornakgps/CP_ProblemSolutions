#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int prefix, nend;
    node *child[2];
    node(){
        prefix = 0;
        nend = -1;
        child[0] = child[1] = NULL;
    }
};

void insert(int n, node *root){
    node *curr = root;
    curr->prefix++;
    for(int i=30;i>=0;i--)
    {
        int x = (((n>>i)&1)==1)?1:0;
        if(curr->child[x] == NULL)
            curr->child[x] = new node();
        curr = curr->child[x];
        curr->prefix++;
    }
    curr->nend = n;
    return;
}

// example question

int query(int i, int y, int k, node *root){
    if(i==-1)
        return root->prefix;
    
    node *curr = root;
    int tempk = (((k>>i)&1)==1);
    int tempy = (((y>>i)&1)==1);
    
    int res = 0;
    if(tempk)
    {
        if(curr->child[tempy] != NULL)
            res += curr->child[tempy]->prefix;
        if(curr->child[tempy^1] != NULL)
            res += query(i-1,y,k,curr->child[tempy^1]);
    }
    else{
        if(curr->child[tempy] != NULL)
            res += query(i-1,y,k,curr->child[tempy]);
    }
    return res;
}


int main(){
 
    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        
        int l = 0, r = (1<<20)-1, res = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            int k = mid;
            int temp = 0;
            node *root = new node();
            insert(temp,root);
            int sum = 0, cursum;
    
            for(int i=0;i<n;i++)
            {
                temp ^= a[i];
                cursum = query(30,temp,k,root);
                sum += cursum;
                insert(temp,root);
            }
            
            if(sum>=x)
            {
                res = k;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        
        cout << res << "\n";
    }

    return 0;
}
