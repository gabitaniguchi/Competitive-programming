#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10)

long long int dp[MAX], h[MAX], n, k;
int const INF = 2e9+10;

int main(){

    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }
    
    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    
    for(int sum=3; sum<=n; sum++) dp[sum]= INF;
    
    for(int sum=3; sum<=n; sum++){
        for(int i=1; i<=k; i++){
            if(sum-i<1) break;
            long long int resp = dp[sum-i] + abs(h[sum]-h[sum-i]);
            dp[sum] = min(dp[sum], resp);
        }
    }
    
    cout<<dp[n]<<endl;
    
    return 0;
}