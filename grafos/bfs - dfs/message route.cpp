#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5 + 10)

vector<int> g[MAX];
queue<int> fila;
int vis[MAX], dist[MAX], pai[MAX];
int n,m;

void bfs(int x){
    memset(dist,-1,sizeof(dist));
    dist[x]=1;
    pai[x] = 0;
    fila.push(x);

    while(!fila.empty()){
        int atual = fila.front();
        if(atual==n) break;
        fila.pop();
        vis[atual] = 1;
        

        for(auto next: g[atual]){
            
            if(vis[next]==1) continue;
            pai[next] = atual;
            //printf("pai de: %d = %d\n",next, atual);
            if(dist[next]==-1) dist[next] = dist[atual]+1;
            vis[next] = 1;
            fila.push(next);
        }
    }
}

int main(){

    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);

    if(dist[n]==-1) printf("IMPOSSIBLE\n");
    else{
        int temp = n;
        stack<int> ans;
  
        while(temp!=0){
            ans.push(temp);
            temp = pai[temp];
        }
        cout<<ans.size()<<endl;
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
            if(!ans.empty()) cout<<" ";
        }
        cout<<endl;

    }

    return 0;
}