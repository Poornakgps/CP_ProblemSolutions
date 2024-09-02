#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, j;

    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;

        int cnt[26]={0};
        for(auto z:s) cnt[z-'a']++;

        int l=0, r=s.size()-1;
        int swaps=0;
        bool ok=1;
        while(l<r)
        {
            pair<int,int> cost={1e9,-1};
            for(int letter=0;letter<26;letter++)
            {
                if(cnt[letter]<2) continue;
                int costL=0, costR=0;
                for(i=l;;i++)
                {
                    if(s[i]-'a'==letter) break;
                    costL++;
                }
                for(i=r;;i--)
                {
                    if(s[i]-'a'==letter) break;
                    costR++;
                }
                cost=min(cost,{costL+costR,letter});
            }
            if(cost.second==-1)
            {
                ok=0;break;
            }
            swaps+=cost.first;

            cnt[cost.second]-=2;
            for(i=l;;i++)
            {
                if(s[i]-'a'==cost.second)break;
            }
            while(i>l)
            {
                swap(s[i],s[i-1]);
                i--;
            }
            for(i=r;;i--)
            {
                if(s[i]-'a'==cost.second)break;
            }
            while(i<r)
            {
                swap(s[i],s[i+1]);
                i++;
            }
            l++,r--;
        }
        if(!ok) cout<<"-1\n";
        else cout<<swaps<<'\n';
    }

}