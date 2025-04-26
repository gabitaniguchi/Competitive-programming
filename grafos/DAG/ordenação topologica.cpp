#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int n,m, vis[MAX];
vector<int> g[MAX];
deque<int> topological;

void dfs(int x){
    vis[x] = 1;

    for(auto next: g[x]){
        if(vis[next]) continue;
        dfs(next);
    }

    topological.push_front(x);
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

    for(auto x: topological) cout<<x<<" ";
    cout<<endl;
    
    return 0;
}