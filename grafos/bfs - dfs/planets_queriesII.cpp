#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define MAXLOG (int)(19)

int up[MAXN][MAXLOG], entr[MAXN], vis[MAXN], v=1, ciclo[MAXN];
int n_ciclo[MAXN], dist[MAXN];
vector<int> g[MAXN], gfull[MAXN], inv[MAXN];
queue<int> fila;
set<int> comp;

void dfs(int i){
    vis[i] = v;
    comp.insert(i);
    if(entr[i]==0) {
        fila.push(i);
    }

    for(auto nxt: gfull[i]){
        if(!vis[nxt]) dfs(nxt);
    }
}

void propaga_dist(int x){
    for(auto nxt: inv[x]){
        dist[nxt] = dist[x]+1;
        propaga_dist(nxt);
    }
}

int jump(int x, int d) {
    for(int i=0; i<MAXLOG; i++) {
        if((d >> i) & 1) x = up[x][i];
    }
    return x;
}

int ambos_ciclo(int a, int b){
    int len = n_ciclo[vis[a]];
    if(dist[b]>dist[a]) return dist[b]-dist[a];
    return len - dist[a] + dist[b];
}

int main()
{_
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=n;i++){
        int x; cin>>x;
        g[i].push_back(x);
        inv[x].push_back(i);
        entr[x] ++;
        up[i][0] = x;

        gfull[i].push_back(x);
        gfull[x].push_back(i);
    }

    for(int j=1; j<MAXLOG; j++) {
        for(int i=1; i<=n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        v++;

        while(!fila.empty()){
            auto at = fila.front();
            fila.pop(); 
            comp.erase(at);

            int nxt = g[at][0];
            entr[nxt]--;
            if(entr[nxt]==0) fila.push(nxt);
        }

        auto ini = *comp.begin();
        ciclo[ini] = 1;
        dist[ini] = 1;
        int at = ini;
        for(auto prox: inv[ini]){
                if(comp.find(prox)==comp.end()){
                    dist[prox]=1;
                    propaga_dist(prox);
                }
            }
        int nxt = g[ini][0];
        n_ciclo[vis[i]]++;
        while(nxt!=ini){
            ciclo[nxt] = 1;
            dist[nxt] = dist[at] + 1;
            n_ciclo[vis[i]]++;

            for(auto prox: inv[nxt]){
                if(comp.find(prox)==comp.end()){
                    dist[prox]=1;
                    propaga_dist(prox);
                }
            }

            at = nxt;
            nxt = g[at][0];
        }
        comp.clear();
    }

    while(q--){
        int a,b;
        cin>>a>>b;

        if(a==b) cout<<0<<endl;

        else if(vis[a]!=vis[b]){
            cout<<-1<<endl;
        }

        else if(ciclo[a]!=0 && ciclo[b]!=0){
            cout<<ambos_ciclo(a,b)<<endl;
        }

        else if(ciclo[a]==0 && ciclo[b]==0){
            if(dist[a]<dist[b]){
                cout<<-1<<endl;
                continue;
            }
            int k = dist[a]-dist[b];
            if(jump(a,k)!=b) cout<<-1<<endl;
            else cout<<k<<endl;
        }

        else if(ciclo[a]==0 && ciclo[b]!=0){
            int k = dist[a];
            a = jump(a,k);
            if(a==b) cout<<k<<endl;
            else{
                k += ambos_ciclo(a,b);
                cout<<k<<endl;
            }
        }

        else if(ciclo[a]!=0 && ciclo[b]==0){
            cout<<-1<<endl;
        }
    }
}