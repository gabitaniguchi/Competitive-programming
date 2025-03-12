#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)
#define ii pair<long long int, int>
#define i pair<int, int>
#define mod (int)(1e9+7)

int n,m;
vector<i> g[MAX];
priority_queue<ii, vector<ii>, greater<ii> >fila;
long long int dist[MAX], routes[MAX], menor[MAX], maior[MAX];

int main(){

    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
    }

    memset(dist, -1, sizeof(dist));
    dist[1] = 0, routes[1]=1, menor[1]=0, maior[1]=0;
    fila.push({0,1});

    while(!fila.empty()){
        long long int peso = fila.top().first;
        int atual = fila.top().second;
        fila.pop();

        if(peso> dist[atual]) continue;
        
        //printf("ATUAL:%d\n", atual);
        for(auto x:g[atual]){
            int next = x.first, w = x.second;

            if(dist[next]!=-1 && dist[next] < w+dist[atual]) continue;

            //printf("NEXT:%d\n", next);

            if(dist[next] == w+dist[atual]){
                routes[next] = (routes[next]+routes[atual])%mod;
                menor[next] = min(menor[atual]+1, menor[next]);
                maior[next] = max(maior[atual]+1,maior[next]);
            }

            if(dist[next]==-1 || dist[next]>dist[atual]+w){
                dist[next] = dist[atual]+w;
                routes[next] = routes[atual];
                menor[next] = menor[atual]+1;
                maior[next] = maior[atual]+1;
                fila.push({dist[next],next});
            }
        }
    }

    cout<<dist[n]<<" "<<routes[n]<<" "<<menor[n]<<" "<<maior[n]<<endl;

    return 0;
}