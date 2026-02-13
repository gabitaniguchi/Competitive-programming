#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (2510)
#define INF (1e18)
#define ii pair<int,int>

int n,m, dist[MAXN], ciclo[MAXN], vis[MAXN], ans[MAXN];
bool check=false, ciclo_to_1=false;
int impossible=0;
vector<int> candidatos;
vector<ii> g[MAXN], inv[MAXN];
vector<pair<ii,int>> edges;


void bellman_ford(){
    for(int v=1; v<=n; v++){
        for(auto [d,p]: edges){
            auto [a,b] = d;
            if(dist[b] > dist[a]+p){
                if(v==n) {
                    ciclo[b] = 1;
                    check=true;
                }
                else {
                    ans[b] = ans[a] -p;
                    dist[b] = dist[a]+p;
                }
            }
        }
    }
}

void check_n_to_ciclo(int x){
    if(ciclo[x]) {
        impossible=1;
        candidatos.push_back(x);
    }
    vis[x]=1;
    for(auto [nxt,p]: inv[x]){
        if(vis[nxt]) continue;
        check_n_to_ciclo(nxt);
    }
}

void check_ciclo_to_1(int x, int t){
    if(x==1){
        impossible=2;
        return;
    }
    vis[x]=t;
    for(auto[nxt,p]: inv[x]){
        if(vis[nxt]==t) continue;
        check_ciclo_to_1(nxt,t);
    }
}

int32_t main()
{_
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({{a,b},-c});
        inv[b].push_back({a,-c});
        if(a==b && b==1 && c>0) ciclo_to_1=true;
    }

    if(ciclo_to_1){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=2;i<=n;i++) dist[i] = INF;

    bellman_ford();

    if(check){
        check_n_to_ciclo(n);
        int t=2;
        for(auto x: candidatos){
            check_ciclo_to_1(x, t);
            t++;
            if(impossible==2){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    
    cout<<ans[n]<<endl;
}