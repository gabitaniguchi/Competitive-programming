#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e3 + 10)

vector<int16_t> g[MAX];
int n,m,origem,destino;
int dist[MAX];
queue <int> fila;

int main(){

    cin>>n>>m>>origem>>destino;
    int linha = 501;

    for(int i=1;i<=m;i++){
        int a;
        cin>>a;

        while(a--){
            int x;
            cin>>x;

            g[linha].push_back(x);
            g[x].push_back(linha);
        }
        linha++;
    }

    fila.push(origem);
    memset(dist, -1, sizeof(dist));
    dist[origem] = 0;

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        if(atual==destino) break;

        for(auto next: g[atual]){
            if(dist[next] == -1){
                dist[next] = dist[atual] + 1;
                fila.push(next);
            }
        }
    }

    int ans = dist[destino]/2;

    printf("%d\n", ans);

    return 0;
}