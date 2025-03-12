#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
vector< pair<int,int>> g[MAX], cord;
int n,q,e, d[MAX], vis[MAX];
const int inf = 1e9+10;
set<pair<int,int>> s;

bool bfs(int i, int f){
    
    memset(vis,0,sizeof(vis));
    memset(d,inf,sizeof(d));
    d[i] = 0;
    s.insert({i,0});

    while(!s.empty()){
        int atual = s.begin()->first;
        s.erase(s.begin());
        vis[atual] = 1;

        if(atual==f){
            if(d[f]<=(e*e)) {
                return true;
            }
            else return false;
        }

        for(int i=0;i<g[atual].size();i++){
            int next = g[atual][i].first;
            int w = g[atual][i].second;

            if(d[next]>d[atual]+w){
                s.erase({next,d[next]});
                d[next] = d[atual] + w;
                if(vis[next]!=1) s.insert({next,d[next]});
            }
        }
    }
    return false;
}

int main(){

    cin>>n>>q>>e;

    cord.push_back({0,0});

    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        cord.push_back({a,b});
    }

    for(int i=1;i<=n;i++){
        int xi = cord[i].first;
        int yi = cord[i].second;

        for(int j=i+1;j<=n;j++){
            int xf = cord[j].first;
            int yf = cord[j].second;
            int d2 = (xf-xi)*(xf-xi) + (yf-yi)*(yf-yi);

            if(d2<=(e*e)) {
                g[i].push_back({j,d2});
                g[j].push_back({i,d2});
            }
        }
    }

    for(int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;

        if(bfs(s,t)==true) printf("S\n");
        else printf("N\n");
        printf("D: %d\n", d[t]);
        
    }

    return 0;
}