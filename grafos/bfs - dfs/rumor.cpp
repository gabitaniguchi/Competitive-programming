#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5 + 10)

vector<int> g[MAX];
int vis[MAX],custo[MAX] ;
int n,m, gold;
long long int ans=0;
const int inf = 1e9+10;

void dfs(int x){
    vis[x] = 1;
    if(custo[x]<gold) gold = custo[x];

    for(auto next: g[x]){
        if(vis[next]==1) continue;
        dfs(next);
    }

}

int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>custo[i];
    }

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        
        if (vis[i]!=1){
            gold = inf;
            dfs(i);
            ans += gold;
        }
    }

    cout<<ans<<endl;

    return 0;
}