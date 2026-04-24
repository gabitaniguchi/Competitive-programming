#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define INF (int)(1e18+10)
#define ii pair<int,int>

int n,m, dp[4][MAXN];
vector<ii> g[MAXN];

int32_t main()
{_
    cin>>n>>m;
    for(int i=1; i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
    }

    for(int i=1;i<=n;i++){
        dp[0][i]=INF;
        dp[1][i]=INF;
        dp[2][i]=INF;
    }

    dp[0][1] = 0;
    dp[2][1] = INF;
    
    priority_queue <ii, vector<ii>, greater<ii>> fila;
    fila.push({0,1});

    while(!fila.empty()){
        auto [d, at] = fila.top(); 
        fila.pop();

        if(d > dp[0][at]) continue;

        for(auto [nxt,w]: g[at]){
            if(dp[0][nxt]>dp[0][at]+w){
                // não usar o desconto
                dp[0][nxt] = dp[0][at] + w;
                fila.push({dp[0][nxt], nxt});
            }
            if(dp[1][nxt]> dp[0][at] + w/2){
                // usar agora o desconto
                dp[1][nxt] = dp[0][at] + w/2;
                fila.push({dp[0][nxt], nxt});
            }
            if(dp[2][nxt] > min(dp[2][at]+w, dp[1][nxt])){
                // já usei o desconto anteriormente
                dp[2][nxt] = min(dp[2][at]+w, dp[1][nxt]);
                fila.push({dp[0][nxt], nxt});
            }
        }
    }

    cout<<dp[2][n]<<endl;
    
}