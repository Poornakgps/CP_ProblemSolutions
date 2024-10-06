#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node *links[26]; // 2 for bit trie
    bool flag = false;
    int cnt = 0;
};


struct Trie{
    Node *root;
    
    Trie(){
        root = new Node();
    }

    void insert(string s){
        
        Node *node = root;

        for(auto i : s){
            if(node->links[i-'a']==NULL){
                node->links[i-'a'] = new Node();
            }
            node = node->links[i-'a'];
        }
        node->flag = true;
        node->cnt++;
    }

    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (node->links[ch - 'a'] == NULL) return false;
            node = node->links[ch - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (node->links[ch - 'a'] == NULL) return false;
            node = node->links[ch - 'a'];
        }
        return true;
    }
};

signed main(){
    int n;
    cin>>n;
    Trie trie;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;

        trie.insert(s);
    }
    for(int i=0;i<n; i++){
        string s;
        cin>>s;
        cout<<trie.search(s)<<endl;;
    }
}