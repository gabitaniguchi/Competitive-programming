#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5 + 10)
#define MOD (int)(1e9+7)

int dp[MAXN], vis[MAXN];
vector<int> g[MAXN];
deque<int> top;

void dfs(int x){
    vis[x]=1;

    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }

    top.push_front(x);
}

int32_t main()
{_
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    dfs(1);

    if(vis[n]==0){
        cout<<0<<endl;
        return 0;
    }

    dp[1] = 1;
    for(auto at: top){
        for(auto nxt: g[at]){
            dp[nxt]+= dp[at]%MOD;
            dp[nxt]%=MOD;
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}