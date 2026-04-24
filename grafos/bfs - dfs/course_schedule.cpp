#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define  MAXN (int)(2e5+10)

int n,m, vis[MAXN];
vector<int> g[MAXN];
deque<int> topological;
bool pos=true;

void dfs(int x){
    vis[x] = 1;

    for(auto next: g[x]){
        if(vis[next]==1){
            pos=false;
            return;
        } 
        if(vis[next]==2) continue;
        dfs(next);
    }

    topological.push_front(x);
    vis[x]=2;
}

int32_t main()
{_
    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i);
        if(!pos) break;
    }

    if(!pos) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(auto x: topological) cout<<x<<" ";
    cout<<endl;
    
    return 0;
}