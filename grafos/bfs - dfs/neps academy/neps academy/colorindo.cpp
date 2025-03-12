#include <bits/stdc++.h>

using namespace std;

int l,c, ix, iy, q, ans=0, m[201][201];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
bool vis[201][201];

void dfs(int x, int y)
{
    vis[x][y] = true;
    ans++;
    
    for(int i=0;i<8;i++)
    {
        int nx = x + dx[i] ;
        int ny = y + dy[i] ;
        
        if(nx==0 || nx>l || ny==0 || ny>c) continue;
        if(vis[nx][ny] == true) continue;
        if(m[nx][ny]<0) continue;
        dfs(nx,ny);
    }
}

int main() {

  scanf("%d %d %d %d %d", &l,&c,&ix,&iy,&q);
  
  for(int i=1;i<=q;i++)
  {
      int a,b;
      
      scanf("%d%d", &a,&b);
      
      m[a][b] = -1;
  }
  
  dfs(ix,iy);
  
  printf("%d\n", ans);

  return 0;
  
}
