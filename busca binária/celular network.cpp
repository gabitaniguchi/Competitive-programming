#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
typedef long long ll;
ll n,m;
ll c[MAX], t[MAX], d=-1;

ll check ( ){
    for(ll i=1;i<=n;i++){
        ll inicio = 1;
        ll fim = m;
        ll x = c[i];
        ll ans = 4000000000;

        while(fim >= inicio){
            ll m = (fim + inicio)/2;

            ans = min(ans, abs(t[m]-x));

            if(t[m]<x) inicio = m + 1;
            else if(t[m]==x) break;
            else fim = m - 1;
        }

        d = max(d,ans);
    }

    return d;
}

int main(){

    cin>>n>>m;

    for(ll i=1;i<=n;i++) cin>>c[i];
    for(ll i=1;i<=m;i++) cin>>t[i];

    cout<<check()<<endl;
    return 0;
}