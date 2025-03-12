#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e4+10)
#define ii pair< int, pair<int,int>>

int n,m,v;
int origem, destino;
int tempo[MAX][205];
int const inf = 1e9+10;
vector<ii> g[MAX];
priority_queue <ii, vector<ii>, greater<ii>> fila;

int main(){

    scanf("%d %d %d", &v, &n, &m);
    
    while(m--){
        int a,b, t, c;
        scanf("%d %d %d %d", &a, &b,&t,&c);

        g[a].push_back({b,{t,c}});
        g[b].push_back({a,{t,c}});
    }

    scanf("%d %d", &origem, &destino);

    for(int i=1;i<=n;i++){
        for(int j=0;j<=v;j++){
            if(i!=origem) tempo[i][j] = inf;
            else tempo[i][j] = 0;
        } 
    }

    fila.push({0, {origem,0}});

    while(!fila.empty()){
        int T = fila.top().first;
        int atual = fila.top().second.first;
        int valor_atual = fila.top().second.second;
        fila.pop();

        //printf("\natual:%d\n", atual);

        if(tempo[atual][valor_atual]<T) continue;
        
        for(auto x: g[atual]){
            int next = x.first;
            int t = x.second.first, custo = x.second.second;

            //printf("tempo[%d][%d] = %d\n", next, custo+valor_atual, tempo[next][custo+valor_atual]);

            if(custo+valor_atual>v) continue;

            if(tempo[next][custo+valor_atual]> tempo[atual][valor_atual] + t){
                tempo[next][custo+valor_atual] = tempo[atual][valor_atual] + t;
                //printf("ALTERA: tempo[%d][%d] = %d\n", next, custo+valor_atual, tempo[next][custo+valor_atual]);
                fila.push({tempo[next][custo+valor_atual], {next, custo+valor_atual}});
            }

        }
    }

    int ans=inf;

    for(int i=0;i<=v;i++){
        if(tempo[destino][i]<ans) ans = tempo[destino][i];
    }

    if(ans==inf) printf("-1\n");
    else printf("%d\n", ans);
    
    return 0;
}