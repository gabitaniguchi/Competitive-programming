#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)
#define ii pair<long long int,int> 

int n,m,k;
long long int dist[MAX][11];
vector<pair<int,int> > g[MAX];
priority_queue<ii, vector<ii>, greater<ii> > fila;
long long int const inf = 1e18 + 10;

int main(){

    cin>>n>>m>>k;

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) dist[i][j] = inf;
    }

    fila.push({0,1});

    while(!fila.empty()){
        long long int w = fila.top().first;
        int atual = fila.top().second;
        fila.pop();

        if(dist[atual][k] < w) continue;

        for(auto x: g[atual]){
            int next = x.first;
            int peso = x.second;

            if(dist[next][k]> w + peso){
                dist[next][k] = w + peso;
                fila.push({dist[next][k], next});
                sort(dist[next], dist[next]+k+1);
                
            }
        }
    }

    for(int i=1;i<=k;i++){
        cout<<dist[n][i];

        if(i<k) cout<<" ";
        else cout<<endl;
    }

    return 0;
}