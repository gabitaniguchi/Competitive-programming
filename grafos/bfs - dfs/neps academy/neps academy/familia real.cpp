#include <bits/stdc++.h>

using namespace std;

vector <int> f[10010];
int vis[10010];
int n,foram; // descendentes e quem foi
queue <int> fila;
map <int,int> pai; // armazena o pai de cada filho
int camada[10010];
int dsc[10010]; // quantos descendentes por camada
int fui[10010]; // quantos descentes foram
int c=0; // medir a camada do grafo

void bfs (int x){
    
    fila.push(x);
    
    while(!fila.empty()){
        
        int atual = fila.front();
        fila.pop();
        
        if(atual ==0) camada[0] = 0;
        else camada[atual] = 1 + camada[pai[atual]];
        vis[atual] = 1;
        
        for(int i=0;i<f[atual].size();i++){
            
            int next = f[atual][i];
            
            if(vis[next]!=1) fila.push(next);
            
        }
        
    }
}


int main(){
    
    cin>>n>>foram;
    
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        
        pai[i] = p;
        
        f[p].push_back(i);
        f[i].push_back(p);
    }
    
    bfs(0);
    
    int c=0; // maior camada;
    
    for(int i=1;i<=n;i++){
       
       int nivel = camada[i];
       c = max (c, nivel);
       dsc[nivel] ++;
    }
    
    for(int i=1;i<=foram;i++){
        int f;
        cin>>f;
        
        int nivel = camada[f];
        fui[nivel] ++;
    }
    
    for(int i=1;i<=c;i++){
        
        double por = (1000000*fui[i]) / dsc[i];
        
        printf("%.2lf", por/10000);
        
        if(i<c) printf(" ");
        else printf("\n");
        
    }
    
    return 0;
}