#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5 + 10)
#define MAXLOG 22
#define ll long long int

ll n, q, up[MAX][MAXLOG], dist[MAX];
int tin[MAX], tout[MAX], t=0;
vector<pair<int,int>> g[MAX];

void dfs(int x){
    tin[x] = t;
    for(auto prox: g[x]){
        int next = prox.first;
        int w = prox.second;
        t++;

        dist[next] = dist[x] + w;
        dfs(next);
    }
    t++;
    tout[x] = t;
}

bool anc(int a, int b){
    if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
    return false;
}

int LCA(int a, int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=MAXLOG-1; i>=0; i--){
        if(!anc(up[a][i],b) && up[a][i]!=0) a = up[a][i];
    }

    return up[a][0];
}

void reinicia(){
    t=0;
    memset(dist, 0, sizeof(dist));
    for(int i=0; i<n; i++){
        g[i].clear();
    }
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    while(true){
        cin>>n;
        if(n==0) break;

        reinicia();

        for(int i=1; i<n; i++){
            int a, d;
            cin>>a>>d;

            g[a].push_back({i,d});
            up[i][0] = a;
        }

        for(int j=1; j<MAXLOG; j++){
            for(int i=0; i<n; i++){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }

        cin>>q;

        dist[0] = 0;
        dfs(0);

        for(int i=1; i<=q; i++){
            int a,b;
            cin>>a>>b;

            cout<< dist[a] + dist[b] - 2*dist[LCA(a,b)];
            if(i<q) cout<<" ";
        }

        cout<<endl;
    }

    return 0;
}