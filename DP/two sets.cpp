#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9+7)

int n, dp[510][510*510];

long long int exp (long long int base, int e){
    long long int ans = 1;

    while(e>0){
        if(e%2==1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e = e/2;
    }

    return ans;
}

int main(){

    cin>>n;

    dp[0][0] = 1;

    for(int i=1; i<=(n*n)/2; i++) dp[0][i] = 0;

    if(n*(n+1)%4 !=0){
        cout<<'0'<<endl;
        return 0;
    }

    for(int i=1; i<=n; i++){
        for(int sum=0; sum<=(n*(n+1))/4; sum++){
            dp[i][sum] = dp[i-1][sum]%MOD;
            if(sum>=i) dp[i][sum] += dp[i-1][sum-i]%MOD;
            dp[i][sum] %= MOD;
        }
    }

    long long int inverso = exp(2, MOD-2);
    long long int ans = ((dp[n][n*(n+1)/4])*inverso)%MOD;
    cout<<ans<<endl;

    return 0;
}