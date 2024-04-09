#include<bits/stdc++.h>


using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
        add_string(words[i]);
    }
    // how to iterate over the trie
    for (int i = 0; i < trie.size(); i++) {
        for (int j = 0; j < K; j++) {
            if (trie[i].next[j] != -1) {
                cout << i << " -> " << trie[i].next[j] << " " << (char)('a' + j) << "\n";
            }
        }
    }

    return 0;
}