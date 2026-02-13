#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)

int vis[MAXN], f[MAXN], n;
vector<int> g[MAXN];

void dfs(int x){
    vis[x] = 1;

    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        dfs(nxt);
        f[x] += f[nxt] + 1;
    }
}

int centroid(int x){
    vis[x] = 1;
    int ans = x;
    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        if((f[nxt]+1)>(n/2)){
            ans = centroid(nxt);
        }
    }

    return ans;
}

int32_t main()
{_
    cin>>n;
    
    for(int i=1; i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    memset(vis, 0, sizeof(vis));
    cout<<centroid(1)<<endl;

}