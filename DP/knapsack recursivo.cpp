#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define W (int)(1e5+10)
#define I (int)(110)

int n,p, v[I], w[W];
ll dp[I][W];
ll const inf = 1e18+10;

ll mochila (int item, int peso){
    if(item==n+1) return 0;
    if(dp[item][peso]!=0) return dp[item][peso];

    dp[item][peso] = mochila(item+1,peso);

    if(peso - w[item] >= 0){
        dp[item][peso] = max(dp[item][peso], mochila(item+1, peso - w[item]) + v[item]);
    }

    return dp[item][peso];
}

int main(){

    cin>>n>>p;

    for(int i=1; i<=n; i++){
        cin>>w[i];
        cin>>v[i];
    }

    cout<<mochila(1,p)<<endl;

    return 0;
}