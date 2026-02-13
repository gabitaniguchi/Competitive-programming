#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define MOD (int)(1e9+7)

int n,m;
int dp[1005][(1<<10)+5];

void solve(int col, int row, int mask, int new_mask){
    if(row==n) {
        dp[col+1][new_mask] = dp[col+1][new_mask] + dp[col][mask]%MOD;
        dp[col+1][new_mask]%=MOD;
        return;
    }

    if(mask & (1<<row)){
        solve(col, row+1, mask, new_mask);
    }

    else{
        solve(col, row+1, mask, new_mask|(1<<row));

        if(row+1<n && !(mask & (1<<(row+1)))) solve(col, row+2, mask, new_mask);
    }
}
 
int32_t main(){
    cin>>n>>m;
    dp[0][0] = 1;


    for(int col=0; col<m;col++){
        for(int mask = 0; mask<(1<<n);mask++){
            if(dp[col][mask]>0){
                solve(col, 0, mask, 0);
            }
        }
    }

    cout<<dp[m][0]<<endl;
    
}