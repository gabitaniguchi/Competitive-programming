#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define MOD (int)(1e9+7)
#define MAXN (int)(1e6+10)
 
int dp[MAXN][2];
 
void precompute(){
    //base 
    dp[1][0] = 1;
    dp[1][1] = 1;
 
    for(int i=2;i<MAXN; i++){
        dp[i][0] = ((dp[i-1][0]*2)%MOD + dp[i-1][1]%MOD)%MOD;
        dp[i][1] = (dp[i-1][0]%MOD + (dp[i-1][1]*4)%MOD)%MOD;
    }
}
 
int32_t main(){
 
    int t;
    cin>>t;
 
    precompute();
 
    while(t--){
        int n, ans;
        cin>>n;
        if(n==1) ans=2;
        else ans = ((dp[n-1][0]*3)%MOD + (dp[n-1][1]*5)%MOD)%MOD;
        cout<<ans<<endl;
    }
 
    return 0;
}