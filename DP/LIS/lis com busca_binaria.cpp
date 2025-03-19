#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(2e5 + 10)
#define inf (int)(1e15)

int v[MAX], n;

int main(){
    
    cin>>n;
    //dp[l] -> menor elemento que uma LIS de tam l termina
    vector<int> dp(n+1, inf);
    dp[0] = -inf;

    for(int i=1; i<=n; i++)dp[i] = inf;

    for(int i=1; i<=n; i++){
        cin>>v[i];
        int l = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if(dp[l-1] < v[i] && v[i]<dp[l]) dp[l] = v[i];
    }

    int ans = 0;
    for(int l=0; l<=n; l++){
        if(dp[l] < inf) ans = l;
    }

    cout<<ans<<endl;

    return 0;
}