#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll h,p,k;


bool check (ll x){
    ll d = k-1;
    ll e = h-k;
    ll sum_d, sum_e;

    if(d<=(x-1)) sum_d = ((2*x - d - 1)*d)/2;
    else sum_d = ((x*(x-1))/2) + (d-x+1);

    if(e<=(x-1)) sum_e = ((2*x - e - 1)*e)/2;
    else sum_e = ((x*(x-1))/2) + (e-x+1);

    // cout<<"X: "<<x<<endl;
    // cout<<"D: "<<sum_d<<endl;
    // cout<<"E: "<<sum_e<<endl;
    // cout<<endl;

    if((sum_d + sum_e)>p-x) return false;
    else return true;
}

ll pillows (ll x){
    ll i = 1;
    ll f = x;
    ll ans = 0;

    while(f>=i){
        ll m = (i+f)/2;

        if (check(m)==false) f = m - 1;

        else{
            ans = max(ans,m);
            i = m + 1;
        }
        
    }

    return ans;   
}
int main(){

    cin>>h>>p>>k;

    ll ans = pillows(p-h+1);

    cout<<ans<<endl;

    return 0;
}