#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int n,a,b,visitado[MAX], camadas[MAX];
vector<int>adj[MAX];

void dfs(int x)
{
  visitado[x] = 1;

  for(int i=0;i<adj[x].size();i++)
    {
      int viz = adj[x][i];

      if(visitado[viz]) continue;
      camadas[viz] = camadas[x] + 1;
      dfs(viz);
    }
}

int main()
{
  scanf("%d %d %d", &n, &a,&b);

  for(int i=1;i<n;i++)
    {
      int u,v;
      scanf("%d %d", &u,&v);

      adj[v].push_back(u);
      adj[u].push_back(v);
    }

  dfs(a);

  printf("%d\n", camadas[b]);
  
  return 0;
}