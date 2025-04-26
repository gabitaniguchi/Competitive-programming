#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9+7)
#define INF (int)(1e9+10)

int dp[(int)(1e6+10)];

int main(){

    int n, x;
    cin>>n>>x;
    int coin[110];

    for(int i=1; i<=n; i++) {
        cin>>coin[i];
    }    

    dp[0] = 1;

    for(int sum=1; sum<=x; sum++){
        for(int i=1; i<=n; i++){
            if(sum-coin[i]<0) break;
            dp[sum] += dp[sum-coin[i]]%MOD;
            dp[sum]%=MOD;
        }
    }

    cout<<dp[x]<<endl;

    return 0;
}