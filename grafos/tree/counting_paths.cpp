#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define MAXLOG (19)

int up[MAXN][MAXLOG+5], qnt[MAXN];
int vis[MAXN], tin[MAXN], tout[MAXN], t=0;
vector<int> g[MAXN];

void dfs(int x){
    vis[x] = 1;
    tin[x] = t;

    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        t++;
        dfs(nxt);
        up[nxt][0] = x;
    }

    t++;
    tout[x] = t;
}

bool anc(int a, int b){
    if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
    return false;
}

int LCA(int a,int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=MAXLOG; i>=0; i--){
        if(!anc(up[a][i], b) && up[a][i]!=0) a = up[a][i];
    }
    return up[a][0];
}

void count(int x){
    vis[x] = 1;
    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        count(nxt);
        qnt[x] += qnt[nxt];
    }
}

int32_t main()
{_
    int n, m;
    cin>>n>>m;

    for(int i=1; i<n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    
    for(int j=1; j<=MAXLOG; j++){
        for(int i=2; i<=n; i++){  
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(m--){
        int a,b;
        cin>>a>>b;

        int lca = LCA(a,b);
        qnt[a]++; qnt[b]++;
        qnt[lca]--; qnt[up[lca][0]]--;
    }

    memset(vis, 0, sizeof(vis));
    count(1);

    for(int i=1;i<=n;i++) cout<<qnt[i]<<" ";
    cout<<endl;
}