#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX (int)(1e3+10)
#define MAX_W (int)(1e5+10)

int n, total, price[MAX], pages[MAX], dp[MAX][MAX_W];

int32_t main(){_

    cin>>n>>total;

    for(int i=1; i<=n; i++) cin>>price[i];
    for(int i=1; i<=n; i++) cin>>pages[i];

    //caso base:
    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int w=0; w<=total; w++){
            dp[i][w] = dp[i-1][w];
            if(w - price[i] >=0) dp[i][w] = max(dp[i][w], pages[i] + dp[i-1][w-price[i]]);
        }
    }

    cout<<dp[n][total]<<endl;

    return 0;
}