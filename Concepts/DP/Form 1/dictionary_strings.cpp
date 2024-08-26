#include <bits/stdc++.h>

using namespace std;

int dictionary_length;
string text;
map<string, bool> dictionary;

int dp[305];

bool rec(int i){

    if(i == text.length()){
        return true;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    bool ans = false;

    for(int j = i; j < text.length(); j++){
        string word = text.substr(i, j - i + 1);
        if(dictionary[word]){
            ans |= rec(j + 1);
        }
    }

    return dp[i]= ans;
}

void solve(){

    cin >> dictionary_length;
    cin >> text;

    for(int i = 0; i < dictionary_length; i++){
        string word;
        cin >> word;
        dictionary[word] = true;
    }

    int n = text.length();
    memset(dp, -1, sizeof(dp));

    if(rec(0)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


}


int main(){

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}