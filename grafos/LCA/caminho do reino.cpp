#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int n, q, origem=-1, ciclo[MAX], tam=0, v=2;
int vis[MAX], dist[MAX], pai[MAX], freq[MAX];
vector<int> g[MAX];
set<int> perif;

void percorre_ciclo (int x){
    tam++;
    vis[x] = 1;
    ciclo[x] = 1;

    for(auto next:g[x]){
        if(vis[next]!=1) {
            dist[next] = dist[x]+1;
            percorre_ciclo(next);
        }
    }
}

void dfs (int x, int v){
    vis[x] = v;

    for(auto next: g[x]){
        if(vis[next]==0) dfs(next, v);

        if(ciclo[next]==1) {
            dist[x] = 1; 
            pai[x] = next;
        }
        else{
            dist[x] = dist[next] + 1;
            pai[x] = pai[next];
        }
            
    }
}

int main(){

    scanf("%d ", &n);

    for(int i=1;i<=n;i++) perif.insert(i);

    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);
        freq[x]++;

        // cidade pertence ao ciclo 
        if(freq[x]>1){
            if(origem==-1) origem = x;
            ciclo[x] = 1;
        }

        g[i].push_back(x);
        perif.erase(x);
    }

    // percorre o grafo uma vez buscando o ciclo
    dist[origem] = 0;
    percorre_ciclo(origem);

    // percorre as periferias
    for(auto p: perif){
        dist[p] = 0;
        dfs(p, v);
        v++;
    }

    scanf("%d", &q);

    while(q--){
        int a,b;
        scanf("%d %d", &a, &b);

        if(a==b){
            printf("0\n");
            continue;
        }
        // se estao na mesma periferia
        if(vis[a]==vis[b] && ciclo[a]!=1) {
            printf("%d\n", abs(dist[a]-dist[b]));
            continue;
        }
        // caso contario encontra a dist até o ciclo e a dist entre o ciclo
        int dista=0, distb=0, ciclo1, ciclo2;

        if(ciclo[a]!=1){
            dista = dist[a];
            ciclo1 = pai[a];
        }

        if(ciclo[b]!=1){
            distb = dist[b];
            ciclo2 = pai[b];
        }

        if(dista==0) ciclo1 = a;
        if(distb==0) ciclo2 = b;

        int dciclo1, dciclo2, ans;

        if(dist[ciclo1]>dist[ciclo2]){
            swap(ciclo1, ciclo2);
            swap(dista, distb);
        }

        dciclo1 = abs(dist[ciclo1] - dist[ciclo2]) + dista;
        dciclo2 = tam - dist[ciclo2] + dist[ciclo1] + distb;

        if(dciclo1<dciclo2) ans = max(dciclo1, distb);
        else if(dciclo2<dciclo1) ans = max(dciclo2, dista);
        else ans = dciclo1;

        printf("%d\n", ans);
    }



    return 0;
}