#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int n, vis[MAX], nivel[MAX];
double esperanca = 0.0;
vector<int> g[MAX];

void dfs(int x, double prob){
    vis[x]=1;
    int filhos = g[x].size();
    if(x!=1) filhos--;
   
    for(auto next: g[x]){
        if(vis[next]) continue;
        nivel[next] = nivel[x]+1;
        dfs(next, prob/filhos);
    }

    if(filhos==0) esperanca += nivel[x]*prob;
}

int main(){

    cin>>n;

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 1.0);

    printf("%.15lf\n", esperanca);
    return 0;
}

