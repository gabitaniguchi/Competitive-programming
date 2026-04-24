#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MOD (int)(1e9+7)

int exp (int base, int e, int mod){
    int ans = 1;
    while(e>0){
        if(e%2==1) ans = (ans*base)%mod;
        base = (base*base)%mod;
        e = e/2;
    }
    return ans;
}

int32_t main()
{_
    int t; cin>>t;

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        int e = (b==0&&c==0)? 1: exp(b,c,MOD-1);
        int ans = (e==0 && a==0)? 1: exp(a,e, MOD);
        cout<<ans<<endl;
    }
    
}