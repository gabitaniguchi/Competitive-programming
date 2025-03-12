#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e4+10)
#define INF (int)(1e9+10)

int n, k, c, dp[MAX][MAX], pref[MAX];

int main(){

    cin>>n>>k>>c;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;

        pref[i] = pref[i-1] + x;
    }

    for(int j=1; j<=k; j++) dp[0][j] = INF;

    //dp[i][k] - soma mínima até i usando k etiquetas
    //base:
    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j>0 && i>=c)
                dp[i][j] = min(dp[i][j], dp[i-c][j-1] + pref[i]- pref[i-c]);
        }
        
    }

    cout<< pref[n] - dp[n][k] << endl;

    return 0;
}