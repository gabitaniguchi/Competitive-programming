#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10)
#define int long long

int n, m, coin[MAX], vis[MAX], dp[MAX];
vector<int> g[MAX], inv[MAX];
set<int> scc;
stack<int> tp;
map<int, int> corresp;

void top_sort(int x){

    vis[x] = 1;
    for(auto nxt: g[x])
        if(!vis[nxt]) top_sort(nxt);
    
    tp.push(x);
}

void kosaraju(int x, int raiz){
    vis[x] = 1;

    for(auto nxt: inv[x]){
        if(vis[nxt]) continue;
        scc.insert(nxt);
        kosaraju(nxt, raiz);
    }
}

void maior_dist(int x){
    vis[x]=1;

    for(auto nxt: g[x]){
        if(!vis[corresp[nxt]]) maior_dist(corresp[nxt]);
        dp[x] = max(dp[x], dp[corresp[nxt]] + coin[x]);
    }
}

int32_t main(){

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>coin[i];
        dp[i] = coin[i];
        corresp[i] = i;
    }

    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        inv[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        top_sort(i);
    }

    memset(vis, 0, sizeof(vis));

    while(!tp.empty()){
        int i= tp.top(); tp.pop();
        if(vis[i]) continue;
        scc.clear();
        kosaraju(i, i);

        for(auto x: scc){
            if(x==i) continue;
            corresp[x] = i;
            for(auto nxt: g[x]){
                if(corresp[nxt]==1 || nxt==i || scc.find(nxt)!=scc.end()) continue;
                g[i].push_back(nxt);
            }
            g[x].clear();
            coin[i] += coin[x];
        }
        dp[i] = coin[i];

        for(int j=0; j<(int)g[i].size();j++){
            if(corresp[g[i][j]]==i) {
                g[i].erase(g[i].begin()+j);
                j--;
            }
        }
    }

    memset(vis, 0, sizeof(vis));

    for(int i=1; i<=n; i++){
        if(!vis[corresp[i]]) maior_dist(corresp[i]);
    }

    int ans =0;
    for(int i=1; i<=n; i++) ans = max(ans, dp[corresp[i]]);
    cout<<ans<<endl;

    // for(int i=1;i<=n; i++){
    //     cout<<"V "<<i<<": ";
    //     for(auto nxt:g[i]) cout<<nxt<<" ";
    //     cout<<endl;
    // }

    return 0;
}
