#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
#define ii pair<int,int>

vector<int> g[MAXN];
int pai[MAXN], dist[MAXN], vis[MAXN];
deque<int> top;

void dfs(int x){
    vis[x] = 1;

    for(auto next: g[x]){
        if(vis[next]) continue;
        dfs(next);
    }

    top.push_front(x);
}

int32_t main()
{_
    int n,m; cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    dfs(1);

    if(vis[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

     while(!top.empty()){
        auto at = top.front();
        top.pop_front();

        for(auto nxt: g[at]){
            if(dist[nxt]<dist[at] + 1){
                dist[nxt] = dist[at]+1;
                pai[nxt] = at;
            }
        }
    }
    stack<int> ans;
    ans.push(n);
    int at=n;
    while(at!=1){
        ans.push(pai[at]);
        at = pai[at];
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
}