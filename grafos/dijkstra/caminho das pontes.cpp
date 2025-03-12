#include <bits/stdc++.h>

using namespace std;

#define MAX 1010
int n,m;
int dist[MAX], vis[MAX];
set <pair<int,int> > fila;
vector< pair<int,int> > g[MAX];
const int INF = 1e9+42;

void bfs (int x){
    memset(dist, INF, sizeof(dist));
    dist[x] = 0;
    fila.insert({0,x});

    while(!fila.empty()){
        int atual = fila.begin()->second;
        fila.erase(fila.begin());

        for(int i=0; i<g[atual].size();i++){
            int next = g[atual][i].first;
            int peso = g[atual][i].second;

            if(dist[next] > dist[atual] + peso){
                fila.erase({dist[next], next});
                dist[next] = dist[atual] + peso;
                fila.insert({dist[next], next});
            }
        }

    }

}

int main(){
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b,p;
        cin>>a>>b>>p;

        g[a].push_back({b,p});
        g[b].push_back({a,p});
    }

    bfs(0);

    cout<<dist[n+1]<<endl;

    return 0;
}