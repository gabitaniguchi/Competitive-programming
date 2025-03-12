#include <bits/stdc++.h>

using namespace std;

#define int long long

int exp (int base, int e, int mod){
    int ans =1;
    while(e>0){
        if(e%2==1) ans = (ans*base)%mod;
        base = (base*base)%mod;
        e = e/2;

    }
    return ans;
}

int32_t main(){

    int a,b,c;
    cin>>a>>b>>c;
    cout<<exp(a,b,c)<<endl;

    return 0;
}