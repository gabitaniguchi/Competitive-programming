#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX (int)(60)
#define ii pair<int,int>

int n,m;


int main(){
    
    while(cin>>n>>m){
        vector<ii> grafo[MAX];
        int custo[MAX], dist[MAX][MAX], recupera[MAX];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = 0;
            }
        }

        for(int i=0; i<n; i++) cin>>custo[i];
        for(int i=1; i<=n; i++){
            int a, b, c;
            cin>>a>>b>>c;

            g[a].push_back({b,c});
            dist[a][b] = c;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) continue;
                    if(dist[i][j] < dist[i][k] + dist[k][j]) {
                        
                    }
                }
            }
        }




    }





    return 0;
}