#include <bits/stdc++.h>

using namespace std;
#define mod (int)(1e9+7)
#define MAX (int)(1e6 + 10)
#define ll long long int

ll dp[MAX]; 
int n, x, coin[110];

int main(){

    cin>>n>>x;

    for(int i=1; i<=n; i++) cin>>coin[i];

    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int sum=1; sum<=x; sum++){
            if(sum - coin[i] >= 0){
                dp[sum] += dp[sum - coin[i]];
                dp[sum] %= mod;
            }
        }
    }

    cout<<dp[x]<<endl;

    return 0;
}