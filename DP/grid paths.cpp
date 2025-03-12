#include <bits/stdc++.h>

using namespace std;
#define mod (int)(1e9+7)
#define MAX (int)(1e3+10)

int n, dp[MAX][MAX];

char mapa[MAX][MAX];

int main(){

    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>mapa[i][j];
        }
    }

    if(mapa[1][1]=='*' || mapa[n][n]=='*'){
        cout<<0<<endl;
        return 0;
    }

    dp[n][n] = 1;
    for(int i=n; i>=1; i--){
        for(int j=n; j>=1; j--){
            if(i==n && j==n) continue;
            if(mapa[i][j]=='*') continue;
            dp[i][j] += (dp[i][j+1] + dp[i+1][j])%mod;
        }
    }

    cout<<dp[1][1];
    return 0;
}