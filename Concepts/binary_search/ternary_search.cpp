#include<bits/stdc++.h>

using namespace std;

#define ll long long


void ternary_search(){


    ll low= 0, high = 1e18;


    while(low<=high){
        ll mid1 = (low + 2*high)/3;
        ll mid2 = (low*2 + high)/3
        
        if(check(mid1)>check(mid2)){
            low = mid1;
        }
        else{
            high = mid2;
        }

    }
}