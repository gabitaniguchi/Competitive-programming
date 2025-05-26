#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int n,m, vis[MAX];
vector<int> g[MAX], inv[MAX];
set<int> scc;
stack<int> tp;

void topol(int x){
    vis[x]=1;
    for(auto nxt: g[x]) if(!vis[nxt]) topol(nxt);
    tp.push(x);
}

void kosaraju(int x){
    vis[x]=1;
    for(auto nxt: inv[x]) {
        if(!vis[nxt]){
            scc.insert(nxt);
            kosaraju(nxt);
        }
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
        if(!vis[i]) topol(i);
    }

    memset(vis,0, sizeof(vis));

    while(!tp.empty()){
        int x=tp.top(); tp.pop();

        if(!vis[x]) kosaraju(x);

        if((int)scc.size()+1==n){
            cout<<"YES\n";
            return 0;
        }

        else{
            cout<<"NO\n";
            int a=x,b;
            for(int i=1; i<=n; i++){
                if(scc.find(i)==scc.end() && i!=x){
                    b=i;
                    break;
                }
            }
            cout<<b<<" "<<a<<endl;
            return 0;
        }
    
    }
    return 0;
}
