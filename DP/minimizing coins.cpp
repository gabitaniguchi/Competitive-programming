#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e6 + 10)
#define ll long long int

int n, target, coin[110];
int const inf = 1e9+10;
ll dp[MAX];

int main(){

    cin>>n>>target;
    
    for(int i=1; i<=target;i++) dp[i] = inf;
    for(int i=1;i<=n;i++) {
        cin>>coin[i];
        dp[coin[i]] = 1;
    }
    
    sort(coin+1, coin+1+n);

    for(int i=1; i<=target; i++){
        for(auto c: coin){
            if(i-c >= 0 ){
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    
    if(dp[target]==inf) dp[target] = -1;

    cout<<dp[target]<<endl;

    return 0;
}