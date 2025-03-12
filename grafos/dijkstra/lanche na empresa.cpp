#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(255)

int n, m, dist[MAX][MAX];
int const inf = 1e9+10;


int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k=1; k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    int maior = 0, ans=inf;

    for(int i=1;i<=n;i++){
        maior = 0;

        for(int j=1;j<=n;j++){
            if(i==j) continue;
            maior = max(maior, dist[i][j]);
        }

        ans = min(ans, maior);
    }

    cout<<ans;

    return 0;
}