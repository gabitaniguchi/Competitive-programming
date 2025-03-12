#include <bits/stdc++.h>

using namespace std;
#define MAX 55
const int inf = 1e9+10;

int n,m,origem, p;
vector<int> g[MAX];
queue<int> fila;
int dist[MAX], vis[MAX];

void bfs(int x, int lim){
    memset(dist, -1, sizeof(dist));
    memset(vis, -1, sizeof(dist));
    dist[x] = 0;
    fila.push(x);

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        vis[atual]=1;

        for(auto next: g[atual]){
            if(vis[next]==1)continue;
            if(dist[next]==-1){
                dist[next] = dist[atual]+1;
                if(dist[next]<lim)fila.push(next);
            }
        }
    }
}

int main (){

    int teste = 1;

    while(true){
        cin>>n>>m>>origem>>p;
        if(n==0) break;

        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        bfs(origem, p);

        for(int i=1;i<=n;i++){
            g[i].clear();
        }

        cout<<"Teste "<<teste<<endl;


        for(int i=1;i<=n;i++){
            if(i!=origem && dist[i]!=-1) cout<<i<<" ";
        }

        cout<<endl<<endl;
        teste++;
    }

    return 0;
}