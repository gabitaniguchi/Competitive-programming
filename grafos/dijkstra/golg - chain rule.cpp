#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)
#define ii pair<int,int>

int n,m, dist0[MAX], distW[MAX];
int origem, d1, d2;
int const inf = 1e9+10;
vector<ii> g[MAX];
priority_queue<ii, vector<ii>, greater<ii>> fila;

int main(){

    scanf("%d %d", &n, &m);

    for(int i=1;i<=m;i++){
        int a,b,t;
        scanf("%d %d %d", &a, &b, &t);

        g[a].push_back({b,t});
        g[b].push_back({a,t});
    }

    for(int i=1;i<n;i++) dist0[i] = inf;
    dist0[0] = 0;
    fila.push({0,0});

    while(!fila.empty()){
        int d = fila.top().first;
        int atual = fila.top().second;
        fila.pop();

        if(dist0[atual]<d) continue;

        for(auto x: g[atual]){
            int next = x.first, w = x.second;

            if(dist0[next] > dist0[atual]+w){
                dist0[next] = dist0[atual]+w;
                fila.push({dist0[next], next});
            }
        }
    }

    for(int i=0;i<n-1;i++) distW[i] = inf;
    distW[n-1] = 0;
    fila.push({0, n-1});

    while(!fila.empty()){
        int d = fila.top().first;
        int atual = fila.top().second;
        fila.pop();

        if(distW[atual]<d) continue;

        for(auto x: g[atual]){
            int next = x.first, w = x.second;

            if(distW[next] > distW[atual] + w){
                distW[next] = distW[atual] + w;
                fila.push({distW[next], next});
            }
        }
    }

    int ans = -1;

    for(int i=0;i<n;i++){
        ans = max(ans, dist0[i]+distW[i]);
    }

    cout<<ans<<endl;

    return 0;
}