#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define MAXN (int)(2e6+10)
#define MOD (int)(1e9+7)
 
int exp(int base, int e){
    int ans = 1;
 
    while(e>0){
        if(e%2==1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e = e/2;
    }
 
    return ans;
}
 
int fat[MAXN], dp[1010], t[1010];
 
int anagrama(int r, int d){
    int den = (fat[r]*fat[d])%MOD;
    int inv = exp(den, MOD-2);
    return (fat[r+d]*inv)%MOD;
}
 
int32_t main(){
    int n, m; 
    cin>>n>>m;
    
    fat[0] = 1;
    for(int i=1;i<=2*n;i++) fat[i] = (fat[i-1]%MOD * i)%MOD;
    
    vector<pair<int,int>> trap;
    
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        trap.push_back({x,y});
    }
    
    trap.push_back({n,n});
    sort(trap.begin(), trap.end());
    
    // dp[i] = nº de formas de chegar até a posição i sem passar
    // por outras armadilhas
    for(int i=1; i<=m+1;i++){
        auto[xi, yi] = trap[i-1];
        t[i] = anagrama(xi-1,yi-1)%MOD;
        if(i==1) dp[i] = t[i]%MOD;
        else{
            dp[i] = t[i]%MOD;
            int sub = 0;
            for(int j=1; j<i; j++){
                auto [xj, yj] = trap[j-1];
                if(yj>yi) continue;
                sub +=((dp[j]%MOD)*(anagrama(xi-xj, yi-yj)%MOD))%MOD;
                sub%=MOD;
            }
            dp[i] = (dp[i]%MOD - sub%MOD + MOD)%MOD;
        }
        dp[i]%=MOD;
    }

    cout<<dp[m+1]<<endl;
}