#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e4+10)

int n, vis[MAX], scc[MAX], comp=0;
vector<int> g[MAX], inv[MAX];
stack<int> tp;

void topol(int x){
    vis[x]=1;
    for(auto nxt:g[x]) if(!vis[nxt]) topol(nxt);
    tp.push(x);
}

void kosaraju(int x){
    vis[x]=1;
    for(auto nxt: inv[x]){
        if(!vis[nxt]) {
            scc[nxt]=comp;
            kosaraju(nxt);
        }
    }
}
int main(){

    cin>>n;

    for(int i=1; i<=n;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        inv[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) topol(i);
    }

    memset(vis, 0, sizeof(vis));

    while(!tp.empty()){
        int x=tp.top();tp.pop();

        if(!vis[x]) {
            scc[x] = comp;
            kosaraju(x);
            comp++;
        }
    }


    for(int i=2; i<=n; i++){
        if(scc[i-1]!=scc[i]) {
            cout<<"N\n";
            return 0;
        }
    }
    cout<<"S\n";

    return 0;
}

