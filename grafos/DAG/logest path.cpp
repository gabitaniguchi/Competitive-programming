#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int vis[MAX], dp[MAX], n, m, ans=0;
vector<int> g[MAX];

void dfs(int x){
    vis[x] = 1;

    for(auto next: g[x]){
        if(!vis[next]) dfs(next);
        dp[x] = max(dp[x], 1+dp[next]);
    }

}

int main(){

    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i);
    }

    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}