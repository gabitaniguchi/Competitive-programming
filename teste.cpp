#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10)


int dist[MAX];
vector<int> grafo[MAX];
queue <int> fila;

void bfs(int origem){
    dist[origem] = 0;
    fila.push(origem);

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(auto next: grafo[atual]){
            dist[next] = dist[atual]+1;
            fila.push(next);
        }
    }

}

int main(){

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        grafo[a].push_back(b);
    }

    bfs(0);

    for(int i=0; i<n; i++) cout<<"dist "<<i<<" "<<dist[i]<<endl;

    return 0;
}