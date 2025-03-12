#include <bits/stdc++.h>

using namespace std;

int n,m,q;
long long int dist[510][510];
long long int const inf = 1e18 + 10;

int main(){
    cin>>n>>m>>q;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }

    while(m--){
        int a,b;
        long long int c;
        cin>>a>>b>>c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--){
        int o,d;
        cin>>o>>d;

        if(dist[o][d]==inf) cout<<"-1"<<endl;
        else cout<<dist[o][d]<<endl;
    }

    return 0;
}