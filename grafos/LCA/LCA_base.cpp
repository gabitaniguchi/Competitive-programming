#include <bits/stdc++.h>

using namespace std;

// 2^18 = 2e5
#define MAXLOG 18
#define MAX (int)(2e5)


int n, up[MAX][MAXLOG], pai[MAX], nivel[MAX];
int t=0, tin[MAX], tout[MAX];
vector<int> g[MAX];

// marca o tempo de entrada e de saída dos vértices
void dfs(int x){

    tin[x] = t;

    for(auto next: g[x]){
        t++;
        if(nivel[next]==-1){
            pai[next] = x;
            up[next][0] = x;  
            nivel[next] = nivel[x] + 1;
            dfs(next);
        }
        
    }

    t++;
    tout[x] = t;
}

void up_incial(){
    for(int j=1; j<MAXLOG; j++){
        for(int i=1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

bool ancestral (int a, int b){
    if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
    return false;
}

int LCA (int a, int b){
    if(ancestral(a,b)) return a;
    if(ancestral(b,a)) return b;

    // procura o primeiro ancestral não comum entre a e b
    for(int i=MAXLOG; i>=0; i--){
        if(!ancestral(up[a][i],b) && up[a][i]!=0) a = up[a][i];
    }

    return up[a][0];
}


int main(){

}