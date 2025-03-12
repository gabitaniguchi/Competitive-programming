#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)
#define ii pair<int, pair<int,int>>

int n,m,k,origem,destino;
int p[MAX], custo[MAX];
vector<pair<int,int>> g[MAX];
map<int,int> preco;
priority_queue<ii, vector<ii>, greater<ii> > q;

void bfs(int origem){
    memset(custo, -1, sizeof(custo));
    custo[origem] = 0;
    q.push({0,{origem,0}});

    while(!q.empty()){
        int atual = q.top().second.first;
        int t1 = q.top().second.second;
        q.pop();

        for(auto x: g[atual]){
            int next = x.first, t2 = x.second;

            //ta dando pau
            if((custo[next]==-1 || custo[next]>custo[atual]) && t1==t2) {
                custo[next] = custo[atual];
                q.push({custo[next], {next,t2}});
            }

            else if(custo[next]==-1 || custo[next]>custo[atual]+preco[t2]){
                custo[next] = custo[atual] + preco[t2];
                q.push({custo[next], {next,t2}});
            }
        }

    }

}

int main(){

    cin>>n>>m>>k;

    for(int i=1;i<=k;i++){
        int v;
        cin>>v;

        preco[i] = v;
    }

    while(m--){
        int a,b,t;
        cin>>a>>b>>t;

        g[a].push_back({b,t});
        g[b].push_back({a,t});
    }

    cin>>origem>>destino;

    bfs(origem);

    cout<<custo[destino]<<endl;

    return 0;
}

// 3 3 2
// 2 5
// 1 2 1
// 2 3 1
// 1 3 2
// 1 3

// 4 5 3
// 1 8 10
// 1 2 1
// 2 4 1
// 4 3 1
// 1 3 3
// 2 3 2
// 1 4
