#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int n,m;
vector<int> g[MAX], inv[MAX];
stack<int> topological;
int vis[MAX], ssc[MAX], ans=0;

void dfs(int x){
    vis[x]=1;
    
    for(auto next: g[x]){
        if(vis[next]) continue;
        dfs(next);
    }

    topological.push(x);
}

void kosaraju(int x){
    vis[x]=1;

    for(auto next: inv[x]){
        if(vis[next]) continue;
        ssc[next] = ans;
        kosaraju(next);
    }
}

int main(){

    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        inv[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof(vis));

    while(!topological.empty()){
        int atual = topological.top();
        if(!vis[atual]){
            ans++;
            ssc[atual] = ans;
            kosaraju(atual);
        }
        topological.pop();
    }

    cout<<ans<<endl;
    for(int i=1; i<=n; i++) cout<<ssc[i]<<" ";
    cout<<endl;

    return 0;
}
