#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)

int vis[MAXN], scc[MAXN], k=0, n, m;
vector<int> g[MAXN], inv[MAXN];
stack<int> top;

// topological order
void dfs(int x){
    vis[x]=1;

    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
    top.push(x);
}

void dfs2(int x){
    vis[x]=1;

    for(auto nxt: inv[x]){
        if(vis[nxt]) continue;
        scc[nxt] = k;
        dfs2(nxt);
    }
}

void kosaraju(){
    for(int i=2; i<=2*m+1;i++) 
        if(!vis[i]) dfs(i);
    
    memset(vis, 0, sizeof(vis));

    while(!top.empty()){
        int at = top.top();
        if(!vis[at]){
            k++;
            scc[at] = k;
            dfs2(at);
        }
        top.pop();
    }
}

void add_sat(int a, bool na, int b, bool nb){
    a = 2*a^na;
    b = 2*b^nb;
    int not_a = a^1;
    int not_b = b^1;

    g[not_a].push_back(b);
    g[not_b].push_back(a);
    inv[b].push_back(not_a);
    inv[a].push_back(not_b);
}

void solution(){
    vector<bool> ans;

    for(int i=1;i<=m;i++){
        if(scc[2*i]==scc[2*i+1]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        if(scc[2*i]>scc[2*i+1]) ans.push_back(true);
        else ans.push_back(false);
    }

    for(auto x: ans){
        x? cout<<"+ ": cout<<"- ";
    }
    cout<<endl;
}

int32_t main()
{_
    cin>>n>>m;

    while(n--){
        char ca, cb;
        int a, b;
        cin>>ca>>a>>cb>>b;

        bool na = ca=='+'? false: true;
        bool nb = cb=='+'? false: true;

        add_sat(a, na, b, nb);
    }

    kosaraju();
    solution();
}