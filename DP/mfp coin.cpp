#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF (int)(1e18+10)
#define MAX (int)(3e5)

int N, n, coin[MAX];
int dp[MAX];

int32_t main(){

    cin>>N;
    n = pow(2,N)-1;

    for(int i=1;i<=n; i++){
        cin>>coin[i];
        dp[i] = 0;
    }

    if(n==1) {
        cout<<coin[1]<<endl;
        return 0;
    }

    dp[1] = coin[1];
    dp[2] = coin[1]+coin[2];
    dp[3] = coin[1]+coin[3];
    int ans = max({dp[1],dp[2],dp[3]});

    for(int i=4; i<=n; i++){
        int op1=0, op2=0;
        int pos1 = i/2;
        int pos2 = (i-1)/2;
        if(i%2==0) op1 = coin[i] + dp[pos1];
        if((i-1)%2==0) op2 = coin[i] + dp[pos2];

        dp[i] = max(op1, op2);
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}