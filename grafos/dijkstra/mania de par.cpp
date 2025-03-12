#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e4 + 10)
#define ii pair<int,int>

int n,m;
int dist[MAX][2];
int const inf = 1e9 + 10;
vector<ii> g[MAX];
priority_queue<ii, vector<ii>, greater<ii>> fila;

int main(){
    cin>>n>>m;

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    for(int i=2;i<=n;i++) dist[i][0] = dist[i][1] = inf;

    dist[1][0] = 0, dist[1][1] = inf;
    fila.push({0,1});

    while(!fila.empty()){
        int atual = fila.top().second;
        fila.pop();

        for(auto x: g[atual]){
            int next = x.first, w = x.second;

            if(dist[next][1]>dist[atual][0]+w){
                dist[next][1] = dist[atual][0] + w;
                fila.push({dist[next][1], next});
            }

            if(dist[next][0]>dist[atual][1]+w){
                dist[next][0] = dist[atual][1]+w;
                fila.push({dist[next][0], next});
            }
        }
    }

    if(dist[n][0]==inf) dist[n][0]=-1;

    cout<<dist[n][0]<<endl;
    
    return 0;
}