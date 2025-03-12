#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX (int)(1e15+10)

int32_t main(){

    int n;
    cin>>n;

    int dp[MAX], sum=1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        if(i%2==0) dp[i] = dp[i/2];
        else dp[i] = dp[i/2] + 1;
        sum+=dp[i];
    }

    cout<<sum<<endl;
    return 0;
}