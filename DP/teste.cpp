#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9+7)
#define MAX (int)(1e6+10)

int dp[MAX], n, x, coin[110];

int main(){
    
    cin>>n>>x;
    
    
    for(int i=1; i<=n; i++) cin>>coin[i];
    
    sort(coin+1, coin+1+n);
    
    dp[0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int sum=1; sum<=x; sum++){
            if(sum-coin[i]>=0){
                dp[sum] += dp[sum-coin[i]]%MOD;
                dp[sum] %= MOD;
            }
        }
    }
    
    cout<<dp[x]<<endl;
    
    return 0;
}