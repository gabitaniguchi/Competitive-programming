#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)

int n, d0[MAXN], dist[MAXN], vis[MAXN];
int pai[MAXN], sub[MAXN];
vector<int> g[MAXN];

void dfs(int x){
    vis[x] = 1;

    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        pai[nxt] = x;
        d0[nxt] = d0[x] + 1;
        dfs(nxt);
        sub[x] += sub[nxt] + 1;
    }
}

int32_t main()
{_
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b; 
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }    

    dfs(1);

    for(int i=2; i<=n; i++) dist[1] += d0[i];

    queue<int> fila;
    memset(vis,0, sizeof(vis));
    for(auto nxt: g[1]) fila.push(nxt);
    vis[1] = 1;

    while(!fila.empty()){
        int i = fila.front(); fila.pop();
        dist[i]= dist[pai[i]] - sub[i] + (n-sub[i]-1) - 1;

        vis[i] = 1;
        for(auto nxt:g[i]){
            if(!vis[nxt]) fila.push(nxt);
        }
    }

    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<endl;
}