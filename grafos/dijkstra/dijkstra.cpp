#include <bits/stdc++.h>

using namespace std;
#define int long long


#define MAX (int)(1e5+10)
#define ii pair<int,int>
#define INF (int)(1e18+10)
int dist[MAX], vis[MAX], arestas, vertices;
vector<ii> grafo[MAX];
// fila de {dist, vértice}
priority_queue <ii, vector<ii>, greater<ii>> fila;

void dijkstra(int origem){
    // inicializo as distâncias e o vetor de visitados
    for(int i=1; i<=vertices; i++) {
        dist[i] = INF;
        vis[i] = 0;
    }
    dist[origem] = 0;

    fila.push({0, origem});

    while(!fila.empty()){
        auto [d, atual] = fila.top();
        fila.pop();

        if(vis[atual]) continue;
        vis[atual] = 1;

        for(auto[next, peso]: grafo[atual]){
            if(vis[next]) continue;
            //checa se encontrei uma distância menor
            if(dist[next] > dist[atual] + peso){
                dist[next] = dist[atual] + peso;
                fila.push({dist[next], next});
            }
        }
    }
}

int32_t main(){

    cin>>vertices>>arestas;

    for(int i=1; i<=arestas; i++){
        int a, b, w;
        cin>>a>>b>>w;

        grafo[a].push_back({b,w});
    }

    dijkstra(1);

    for(int i=1; i<=vertices; i++) cout<<dist[i]<<" ";
    cout<<endl;

    return 0;
}