#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define MAXW (int)(1e5+10)
#define MAXN (int)(110)

int n, p, w[MAXN], v[MAXN];
ll dp[MAXN][MAXW];

int main(){

    cin>>n>>p;

    for(int i=1; i<=n; i++){
        cin>>w[i]>>v[i];
    }

    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int peso=0; peso<=p; peso++){
            dp[i][peso] = dp[i-1][peso];
            if(peso >= w[i]) {
                dp[i][peso] = max(dp[i][peso], dp[i-1][peso-w[i]] + v[i]);
            }
        }
    }

    cout<<dp[n][p]<<endl;

    return 0;
}