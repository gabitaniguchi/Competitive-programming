#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10 )

int dp[MAX], h[MAX], n;

int main(){

    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }
    
    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + abs(h[i]-h[i-1]);
        dp[i] = min(dp[i], dp[i-2]+abs(h[i-2]-h[i]));
    }
    
    cout<<dp[n]<<endl;
    
    return 0;
}