#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[50050];
bool ja_passei[50050];

void dfs(int v)
{
  ja_passei[v] = true;

  for(int i=0;i<(int)grafo[v].size();i++)
  {
    int vizinho = grafo[v][i];
    if(!ja_passei[vizinho]) dfs(vizinho);
  }
}

int main()
{
   int n,m;
   cin>>n>>m;

   for(int i=1;i<=m;i++)
   {
     int a,b;
     cin>>a>>b;
    
     grafo[a].push_back(b);
     grafo[b].push_back(a);
   }

   int familias = 0;

   for(int i=1;i<=n;i++)
   {
     if(!ja_passei[i]) 
     {
         familias++;
         dfs(i);
     } 
   }
  cout<<familias<<endl;

  return 0;
}