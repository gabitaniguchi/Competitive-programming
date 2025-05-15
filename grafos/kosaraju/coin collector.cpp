#include <bits/stdc++.h>
#define int long long
#define MAX (int)(1e5+10)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,m;
int vis[MAX], custo[MAX], dp[MAX];
vector<int> g[MAX], inv[MAX];
set<int> filhos;
stack<int> tp;

void dfs(int x){
    vis[x] = 1;
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
        kosaraju(next);
        filhos.insert(next);
    }
}
void longest_path(int x){
    vis[x]=1;

    for(auto next: g[x]){
        if(vis[next]) continue;
        longest_path(next);
        dp[x] = max(dp[x], dp[next]+custo[x]);
    }
}

int32_t main()
{_

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>custo[i];
        dp[i] = custo[i];
    }
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
        filhos.clear();

        if(!vis[atual]){
            kosaraju(atual);
            cout<<"DAG "<<atual<<" ";

            for(auto next: filhos){
                for(auto prox: g[next]){
                    if(filhos.find(prox)==filhos.end()) 
                        g[atual].push_back(prox);
                }
                cout<<next<<" ";
                g[next].clear();
                custo[atual] += custo[next];
                dp[atual] = custo[atual];
            }
            cout<<endl;
        }
        tp.pop();
    }

    memset(vis,0, sizeof(vis));

    for(int i=1; i<=n; i++){
        if(!vis[i]) longest_path(i);
    }

    int ans =0;

    for(int i=1; i<=n; i++) ans = max(ans, dp[i]);

    cout<<ans<<endl;
}
