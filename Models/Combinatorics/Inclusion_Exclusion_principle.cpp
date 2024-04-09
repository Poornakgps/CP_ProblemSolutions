// Task: given two numbers n and r, count the number of integers in the interval [1;r] 
// that are relatively prime to n (their greatest common divisor is 1).

int solve (int n, int r) {
    vector<int> p;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            p.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back (n);

    int sum = 0;
    for (int msk=1; msk<(1<<p.size()); ++msk) {
        int mult = 1,
            bits = 0;
        for (int i=0; i<(int)p.size(); ++i)
            if (msk & (1<<i)) {
                ++bits;
                mult *= p[i];
            }

        int cur = r / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }

    return r - sum;
}


    #include <bits/stdc++.h>
    using namespace std;
     
/*
This problem of Oz is very straight forward. You are given N distinct prime integers i.e p1, p2,..., pN and an interval [L,R]. 
Calculate number of integers in this interval that are divisible by at least one of the given primes.
*/
    #define rep(i,n) for(i=0;i<n;i++)
    #define ll long long
    #define pii pair<int,int>
    #define mp make_pair
    #define pb push_back


    int main()
    {
        int t;
        cin>>t;
        assert(1<=t && t<=10);
        while(t--)
        {
         ll int i,j,n,l,r;
            cin>>n>>l>>r;
            
         assert(1<=n && n<=10);
         assert(1<=l && l<=r);
         assert(l<=r && r<=1000000000000000000);
            vector<ll int>pr(n);
            rep(i,n)
            {
                cin>>pr[i];
                assert(1<pr[i] && pr[i]<1000);
            }
            
            ll  int ans=0,mask=0,lim=(1<<n);
            for(mask=0; mask<lim; mask++)
            {
                int co=__builtin_popcountll(mask);
                if(co==0)
                continue;
                ll int val=1,i=0;
                while(i<n)
                {
                    if( (mask&(1<<i)))
                        {
                            val*=pr[i];
                            if(val>r || val<0)
                                break;
                        }
                    i++;
                }
                if(i<n)
                    continue;
                ll int temp= r/val - (l-1)/val;
                temp=max(temp,(ll)0);
                if(val>r+r)
                temp=0;
                if(co%2)
                    ans+=temp;
                else
                    ans-=temp;
            }
            
        cout<<ans<<"\n";
        
        }      
        return 0;
    }