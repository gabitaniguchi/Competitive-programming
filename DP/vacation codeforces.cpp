#include <bits/stdc++.h>

using namespace std;
#define INF (int)(1e5+10)

int dp[110][4];
int at[115];

int main(){

    int n;
    cin>>n;
    for(int i=1; i<=n; i++)  
        cin>>at[i];

    for(int i=1; i<=n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        if(at[i]==0) continue;

        if(at[i]==1 || at[i]==3) dp[i][1] = max(dp[i-1][0]+1, dp[i-1][2]+1);
        if(at[i]==2 || at[i]==3) dp[i][2] = max(dp[i-1][0]+1, dp[i-1][1]+1);
    }
 
    cout<<n-max({dp[n][0], dp[n][1], dp[n][2]})<<endl;

    return 0;
}