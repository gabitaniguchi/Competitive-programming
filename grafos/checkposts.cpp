#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)
#define INF (int)(1e9+10)
#define MOD (int)(1e9+7)
#define int long long

int n,m, vis[MAX], custo[MAX];
int ans=0;
pair<int,int> menor;
vector<int> comp;
stack<int> tp;
vector<int> g[MAX], inv[MAX];

void dfs(int x){
    vis[x]=1;

    for(auto next: g[x]){
        if(vis[next]) continue;
        dfs(next);
    }

    tp.push(x);
}

void kosaraju(int x){
    vis[x] = 1;

    for(auto next: inv[x]){
        if(vis[next]) continue;
        if(menor.first==custo[next]) menor.second++;
        else if(menor.first>custo[next]) menor = {custo[next],1};
        kosaraju(next);
    }
}

int32_t main(){

    cin>>n;
    for(int i=1; i<=n; i++) cin>>custo[i];

    cin>>m;

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

    while(!tp.empty()){
        int atual = tp.top();
        if(!vis[atual]){
            menor = {custo[atual], 1};
            kosaraju(atual);
            ans += menor.first;
            comp.push_back(menor.second);
        }
        tp.pop();
    }
    int p=1;

    for(auto x: comp){
        p = p*x % MOD;
        p%=MOD;
    }

    cout<<ans<<" "<<p<<endl;

    return 0;
}
