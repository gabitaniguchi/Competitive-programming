#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5 + 10)
#define ii pair<long long int,int>

int n,m;
vector<pair<int, int>> g[MAX];
long long int dist[MAX];
priority_queue<ii, vector<ii>, greater<ii> > q;

int main(){

    cin>>n>>m;

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
    }

    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    q.push({0,1});

    while(!q.empty()){
        auto atual = q.top(); 
        q.pop();
        int x = atual.second;
        int d = atual.first;
        if(dist[x] < d) continue;

        for(auto next: g[x]){
            int v = next.first;
            int w = next.second;
            if(dist[v]==-1 || (dist[v] > dist[x]+w)){
                dist[v] = dist[x] + w;
                q.push({dist[v],v});
            }
        }

    }
        
    for(int i=1;i<=n;i++){
        cout<<dist[i];
        if(i<n) cout<<" ";
        else cout<<endl;
    }

    return 0;
}