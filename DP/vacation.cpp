#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+5)

int n, dp[3][MAX], happy[MAX][3];

int main(){

    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin>>happy[i][j];
        }
    }

    // caso base:
    dp[0][1] = happy[1][0];
    dp[1][1] = happy[1][1];
    dp[2][1] = happy[1][2];

    for(int i=2; i<=n; i++){
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + happy[i][0];
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + happy[i][1];
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + happy[i][2];

    }

    int ans = max(dp[0][n], dp[1][n]);
    ans = max(ans, dp[2][n]);

    cout<<ans<<endl;

    return 0;
}