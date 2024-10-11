#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define popc __builtin_popcountll
#define mod 1000007
#define endl '\n'
#define debug(x) cout<< #x<< " "<< x<< endl;

using namespace std;
ll n;
struct Matrix{
    vector<vector<double>> v = vector<vector<double>> (n, vector<double> (n));
    void operator *=(const Matrix& B){
        vector<vector<double>> mul(n, vector<double>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    mul[i][k]+=v[i][j]*B.v[j][k];
                }
            }
        }
        v=mul;
    }
};

Matrix expo(Matrix A, ll m){
    Matrix result;
    for(int i=0;i<n;i++) result.v[i][i]=1;
    while(m){
        if(m%2!=0){
            result*=A;
        }
        m/=2;
        A*=A;
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; t=1;
    ll cn=0;
    while(t--){
        ll nn; double p;
        cin>> nn>> p;
        n=2;
        Matrix A;
        A.v={{1-p, p}, {p, 1-p}};
        Matrix B=expo(A, nn);
        double ans=B.v[0][0];
        cout<< setprecision(12)<< ans<< endl;
    }
    return 0;
}
