#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD (int)(1e9 + 7)

int t,a,b;

int exp (int base, int e){
    int ans = 1;

    while(e>0){
        if(e%2==1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e = e/2;
    }

    return ans%MOD;

}

int32_t main(){

    cin>>t;

    for(int i=1;i<=t;i++){
        cin>>a;
        cout<<(exp(a,MOD-2)*1)%MOD<<endl;
    }

    return 0;
}

