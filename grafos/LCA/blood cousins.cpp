#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5 + 10)
#define MAXLOG 19

pair<int,int> v_inicial[MAX];
int n, m, level[MAX], up[MAX][MAXLOG];
int tin[MAX], tout[MAX], t=0;
vector<int> g[MAX];
vector<int> nivel[MAX];

void dfs (int x){
    tin[x] = t;

    for(auto next: g[x]){
        t++;
        level[next] = level[x] + 1;
        nivel[level[next]].push_back(next);
        dfs(next);
    }

    t++;
    tout[x] = t;
}

bool anc(int a, int b){
    if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
    return false;
}

int LCA (int a, int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=MAXLOG-1; i>=0; i--){
        if(anc(up[a][i],b) && up[a][i]!=0) a = up[a][i];
    }

    return up[a][0];
}

int busca_binaria (int tin_lca, int tout_lca, int v){
    int i=0;
    int n = level[v];
    int f = nivel[n].size()-1;

    int inicio, fim;

    while(i<=f){
        int mid = (i+f)/2;
        if(tin[nivel[n][mid]] < tin_lca) i = mid+1;
        else{
            inicio = mid;
            f = mid-1;
        }
    }

    i=inicio, f = nivel[n].size()-1;
    while(i<=f){
        int mid = (i+f)/2;
        if(tout[nivel[n][mid]] > tout_lca) f = mid-1;
        else{
            fim = mid;
            i = mid+1;
        } 

    }
    return fim - inicio;
}


int main(){

    cin>>n;

    for(int i=1; i<=n;i++){
        int pai;
        cin>>pai;

        g[pai].push_back(i);
        up[i][0] = pai;
    }

    level[0] = 0;
    dfs(0);

    for(int j=1; j<MAXLOG; j++){
        for(int i=1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    for(int i=1; i<=n; i++){
        v_inicial[i-1] = {tin[i], tout[i]};
    }

    cin>>m;

    while(m--){
        int v, p;
        cin>>v>>p;

        int lca=v;
        for(int i=0; i<MAXLOG; i++){
            if(p & (1<<i)) lca = up[lca][i];
        }

        if(up[v][0]==0 || lca==0) {
            printf("0 ");
            continue;
        }

        int tin_lca = tin[lca];
        int tout_lca = tout[lca];

        cout<<busca_binaria(tin_lca, tout_lca, v)<<" ";
    }

    cout<<endl;

    return 0;
}