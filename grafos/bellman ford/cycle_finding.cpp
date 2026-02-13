#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (2510)
#define INF (1e18)
#define ii pair<int,int>

int n,m, dist[MAXN], vis[MAXN], pai[MAXN], ciclo=0;
vector<ii> g[MAXN];
vector<pair<ii,int>> edges;


void bellman_ford(){
    for(int v=1; v<=n; v++){
        for(auto [d,p]: edges){
            auto [a,b] = d;
            if(dist[b] > dist[a]+p){
                if(v==n) {
                    ciclo=b;
                }
                else dist[b] = dist[a]+p;
                pai[b] = a;
            }
        }
    }
}

int32_t main()
{_
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({{a,b},c});
        g[a].push_back({b,c});
    }

    for(int i=2;i<=n;i++) dist[i] = INF;

    bellman_ford();

    if(!ciclo) {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    int x = ciclo;
    for (int i = 0; i < n; i++) x = pai[x];
    stack<int>ans;
    int at=x;
    
    while(true){
        ans.push(at);
        if(ans.size()>1 && at==x) break;
        at = pai[at];
    }

    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }

    cout<<endl;

}