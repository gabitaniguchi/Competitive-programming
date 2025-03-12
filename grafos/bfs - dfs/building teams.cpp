#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)

int n,m;
vector<int> g[MAX];
int color[MAX];
int vis[MAX], pai[MAX];
int ans = 0;
queue<pair<int,int> > fila;

int troca(int c){
    if(c==1) return 2;
    else return 1;
}

void bfs (int x, int c){
    
    fila.push({x,c});

    while(!fila.empty()){
        int atual = fila.front().first;
        int cor = fila.front().second;
        fila.pop();
        
        vis[atual] = 1;
        color[atual] = cor;

        if(pai[atual]!=0 && color[pai[atual]]==color[atual]) ans = -1;
        if(ans==-1) break;
    
        for(auto next: g[atual]){
            if(vis[next]!=1) fila.push({next,troca(cor)});
            pai[next] = atual;
        }
    }
}

int main(){

    cin>>n>>m;

    while(m--){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]!=1) {
            pai[i] = 0;
            bfs(i,1);
        }
        if(ans==-1) break;
    }

    if(ans == -1) cout<<"IMPOSSIBLE"<<endl;

    else{
        for(int i=1;i<=n;i++){
            cout<<color[i];
            if(i!=n) cout<<" ";
            else cout<<endl;
        }
    }

}