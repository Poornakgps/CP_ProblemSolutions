
#include<bits/stdc++.h>

using namespace std;



signed main(){

    int n, x;
    cin>>n>>x;

    int weight[n], rides[n];


    pair<int, int> best[1<<n][n];
    best[0] = {1, 0};

    for(int mask = 1; mask<(1<<n); i++){
        best[mask][0] = {n+1, 0};

        for(int p = 0; p<n; p++){
            if((mask&(1<<p))){
                auto option = best[mask^(1<<p)];
                
                if(weight[p]+ option.second<=x){
                    // add p to an existing ride
                    option.second += weight[p];
                }
                else{
                    // reserve a new ride for p
                    options.first++;
                    option.second = weight[p];
                }
            }
            best[mask] = min(best[mask], option);
        }
    }

}