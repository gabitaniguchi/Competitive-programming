#include <bits/stdc++.h>

using namespace std;

int l,c;
int xi,yi,xf=0,yf=0;
int mapa[12][12];
queue<pair<int,int>> fila;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int camada[12][12], vis[12][12];

void bfs(int x, int y){
    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            camada[i][j]=-1;
        }
    }
    camada[x][y] = 0;
    fila.push({x,y});

    while(!fila.empty() && yf==0){
        auto atual = fila.front();
        fila.pop();

        vis[atual.first][atual.second] = 1;

        for(int i=0;i<4;i++){
            int nx = atual.first + dx[i];
            int ny = atual.second + dy[i];

            if(ny>c||ny<1||nx>l||nx<1||vis[nx][ny]==1||mapa[nx][ny]==2) continue;
            if(camada[nx][ny]==-1) camada[nx][ny] = camada[atual.first][atual.second] + 1;
            if(mapa[nx][ny]==0){
                yf = ny;
                xf = nx;
                break;
            }
            fila.push({nx,ny});
            vis[nx][ny] = 1;
        }

    }
}

int main(){
    
    cin>>l>>c;

    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            cin>>mapa[i][j];
            if(mapa[i][j]==3){
                xi = i;
                yi = j;
            }
        }
    }

    bfs(xi,yi);

    cout<<camada[xf][yf]<<endl;

    return 0;
}