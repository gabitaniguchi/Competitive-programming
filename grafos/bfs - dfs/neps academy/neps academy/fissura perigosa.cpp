#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int N,f, M[505][505];
bool vis[505][505];

void fissura(int x, int y, int forca)
{
    vis[x][y] = true;
    if(M[x][y]>forca) return;
    M[x][y] = -1;
    
    for(int i=0;i<4;i++)
    {
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        
        if(new_x<0 || new_x>=N || new_y<0 || new_y>=N) continue;
        if(vis[new_x][new_y]==true)continue;
        
        if(M[new_x][new_y]<=forca)
        {
            fissura(new_x, new_y,f);
        } 
        
    }
}

int main()
{
    scanf("%d %d", &N, &f);
    string linha;
    
    getline(cin,linha);
    
    for(int i=0;i<N;i++)
    {
        getline(cin,linha);
        
        for(int j=0;j<N;j++)
        {
            M[i][j] = linha[j] - '0';
        }
    }
    
    fissura(0,0,f);
    
    for(int i=0;i<N;i++)
    {
        
        for(int j=0;j<N;j++)
        {
           if(M[i][j] > 0) printf("%d", M[i][j]);
           else printf("*");
        }
        
        printf("\n");
    }
    
    
    return 0;
}