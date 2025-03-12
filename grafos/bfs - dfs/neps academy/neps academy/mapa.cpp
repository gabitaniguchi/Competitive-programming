#include <bits/stdc++.h>

using namespace std;

int l,c; //linhas e colunas do mapa
char mapa[110][110];
int vis[110][110];
int xi,yi, xf, yf; //posições iniciais e finais

int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0};

void dfs (int x, int y){
    
    vis[x][y] = 1;
    xf = x;
    yf = y;
    
    for(int i=0;i<4;i++){
        
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        
        if(mapa[new_x][new_y] == 'H' && vis[new_x][new_y]!=1){
            dfs(new_x, new_y);
        }
        
    }
    
    
}


int main(){
    
    cin>>l>>c;
    
    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            cin>> mapa[i][j];
            
            if(mapa[i][j] == 'o'){
                xi = i;
                yi = j;
            }
        }
    }
    
    dfs(xi,yi);
    
    printf("%d %d\n", xf,yf);
    
    return 0;
}