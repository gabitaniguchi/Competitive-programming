#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(2e5+10)
#define MAXLOG 19
#define int long long int

int n, m, mst[MAX], pai[MAX], peso[MAX], sum=0;
int tin[MAX], tout[MAX], t=0;
int vis[MAX], up[MAX][MAXLOG], dist[MAX][MAXLOG];
vector<pair<pair<int,int>, pair<int,int>>> edges;
vector<pair<int, pair<int,int>>> entrada;
vector<pair<int, int>> g[MAX];

int find(int x){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    int x = pai[a];
    int y = pai[b];

    if(peso[y]>peso[x]) swap(x,y);

    pai[y] = x;
    peso[x] += peso[y];
}

void dfs(int x){
    tin[x] = t;
    vis[x] = 1;

    for(auto p: g[x]){
        int next = p.first;
        int w = p.second;

        if(vis[next]!=1){
            t++;
            up[next][0] = x;
            dist[next][0] = w;
            dfs(next);
        }
    }

    t++;
    tout[x] = t;
}

bool anc(int a, int b){
    if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
    return false;
}

int LCA(int u, int v){

    int maior = 0;

    for(int i=MAXLOG-1; i>=0; i--){
        if(!anc(up[u][i], v) && up[u][i]!=0) {
            maior = max(maior, dist[u][i]);
            u = up[u][i];
        }
    }
    return maior = max(maior, dist[u][0]);
}

int32_t main(){

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        pai[i]=i;
        peso[i] = 1;
    }

    for(int i=1; i<=m; i++){
        int a,b,w;
        cin>>a>>b>>w;

        edges.push_back({{w,i}, {a,b}});
        entrada.push_back({w, {a,b}});
    }

    sort(edges.begin(), edges.end());

    for(auto e: edges){
        int w = e.first.first;
        int i = e.first.second;
        int a = e.second.first;
        int b = e.second.second;

        if(find(a)==find(b)) continue;
        else{
            mst[i] = 1;
            sum += w;
            join(a,b); 
            g[a].push_back({b,w});
            g[b].push_back({a,w});
        }
    }

    dfs(1);

    for(int j=1; j<MAXLOG; j++){
        for(int i=1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    for(int j=1; j<MAXLOG; j++){
        for(int i=2; i<=n; i++){
            dist[i][j] = max(dist[i][j-1], dist[up[i][j-1]][j-1]);
        }
    }

    for(int i=1; i<=m; i++){
        if(mst[i]==1) cout<<sum<<endl;
        else {
            int w = entrada[i-1].first;
            int a = entrada[i-1].second.first;
            int b = entrada[i-1].second.second;
            
            int r1 = LCA(a,b);
            int r2 = LCA(b,a);
            int maior;
            if(anc(a,b)) maior = r2;
            else if(anc(b,a)) maior = r1;
            else maior = max(r1,r2);

            int resp = sum-maior+w;

            cout<<resp<<endl;
        }
    }

    return 0;
}