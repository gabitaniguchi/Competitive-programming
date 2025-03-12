#include <bits/stdc++.h>

using namespace std;
#define mod (int)(1e9 + 7)
#define MAX (int)(1e6+10)
#define ll long long int

ll dp[MAX], x;

ll dice (int x){
    if(x==0) return dp[x] = 1;
    if(dp[x]!=0) return dp[x];

    for(int i=1; i<=6; i++){
        int temp = x - i;

        if(temp<0) break;

        dp[x] += dice(temp)%mod;
    }

    return dp[x]%=mod;
}

int main(){

    cin>>x;

    dp[x] = dice(x);

    cout<<dp[x]<<endl;

    return 0;
}