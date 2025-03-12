#include<bits/stdc++.h>

using namespace std;

#define MAX 1010

int n,m, visitado[MAX];
vector <int> adj[MAX];
queue<int>v;

void bfs(int x)
{
    visitado[x] = 1;
    v.push(x);
    
    while(!v.empty())
    {
       
        int atual = v.front();
        v.pop();
        
        for(int i=0;i<adj[atual].size();i++)
        {
          int viz = adj[atual][i];
        
          if(visitado[viz]) continue;
          v.push(viz);
          visitado[viz] = 1;
            
        }
        
        
    }
}


int main()
{
    scanf("%d %d", &n,&m);
    
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;
    
    for(int i=1;i<=n;i++)
    {
        if(!visitado[i])
        {
           ans ++;
           bfs(i); 
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}