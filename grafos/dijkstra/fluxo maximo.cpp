#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5 + 10)
#define ii pair<int,int> 
int const inf = 1e9 + 10;

int n,m,origem,destino, fluxo[MAX], vis[MAX];
vector<ii> g[MAX];
priority_queue<ii> fila;

int main(){

    cin>>n>>m>>origem>>destino;

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
    }

    fila.push({inf,origem});
    for(int i=2;i<=n;i++) fluxo[i] = -1;

    while(!fila.empty()){
        int atual = fila.top().second;
        int agua = fila.top().first;
        fila.pop();

        vis[atual] = 1;
        
        for(auto x: g[atual]){
            int next = x.first, custo = x.second;
            if(custo>agua) fluxo[next] = max(fluxo[next],agua);
            else fluxo[next] = max(fluxo[next],custo);
            if(vis[next]!=1) fila.push({fluxo[next],next});
        }
    }

    cout<<fluxo[destino]<<endl;

    return 0;
}