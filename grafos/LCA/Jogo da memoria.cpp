#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(5e4 + 10)
#define MAXL 18

int n, par[MAX], anc[MAX][MAXL], pai[MAX], nivel[MAX];
int tin[MAX], tout[MAX], t=0;
queue<pair<int,int>> cartas;
vector<int> g[MAX];

void dfs(int x){

    tin[x] = t;

    for(auto next: g[x]){
        t++;
        if(nivel[next]==-1){
            pai[next] = x;
            anc[next][0] = x;  
            nivel[next] = nivel[x] + 1;
            dfs(next);
        }
        
    }

    t++;
    tout[x] = t;
}

bool ancestral (int a, int b){
    if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
    return false;
}

int LCA (int a, int b){
    if(ancestral(a,b)) return a;
    if(ancestral(b,a)) return b;

    for(int i=MAXL-1; i>=0; i--){
        if(!ancestral(anc[a][i],b) && anc[a][i]!=0) a = anc[a][i];
    }

    return anc[a][0];
}

int main(){

    cin>>n;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;

        if(par[x]>0) {
            cartas.push({par[x], i});
        }

        else par[x] = i;
    }

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++) nivel[i] = -1;
    nivel[1] = 1;

    dfs(1);

    for(int j=1; j<MAXL; j++){
        for(int i=1; i<=n; i++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }

    long long int ans = 0;

    while(!cartas.empty()){
        int a = cartas.front().first;
        int b = cartas.front().second;
        cartas.pop();

        int lca = LCA(a, b);

        ans += nivel[a] + nivel[b] - 2*nivel[lca]; 
    }

    cout<<ans<<endl;

    return 0;
}