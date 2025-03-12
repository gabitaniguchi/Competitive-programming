#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)

int n,m,d, ans = -1;
int v[MAX], dist[MAX], pai[MAX];
vector<pair<int,int>> g[MAX];
queue <int> fila;
stack<int> caminho;

bool bfs(int lim){
    
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    pai[1] = 0;
    fila.push(1);

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(auto next: g[atual]){
            int v = next.first, peso = next.second;
            if(dist[v]==-1 && peso<=lim && dist[atual]<d){
                pai[v] = atual;
                dist[v] = dist[atual] + 1;
                fila.push(v);
            }

        }
    }
    if(dist[n]==-1 || dist[n]>d) return false;
    else return true;
}

int busca (int m){
    int i=1;
    int f=m;

    while(i<=f){
        int meio = (i+f)/2;

        if(bfs(v[meio])) {
            ans = v[meio];
            f = meio-1;
        }

        else i = meio+1;
    }

    return ans;
}


int main(){

    cin>>n>>m>>d;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});
        v[i] = c;
    }

    sort(v,v+m+1);

    ans = busca(m);

    if(ans == -1) cout<<ans<<endl;

    else{
        int x = n;
        bfs(ans);

        while(x!=0){
            caminho.push(x);
            x = pai[x];
        }

        cout<<caminho.size()-1<<endl;
        
        while(!caminho.empty()){
            cout<<caminho.top();
            caminho.pop();
            if(caminho.empty()) cout<<endl;
            else cout<<" "; 
        }

    }

    return 0;
}