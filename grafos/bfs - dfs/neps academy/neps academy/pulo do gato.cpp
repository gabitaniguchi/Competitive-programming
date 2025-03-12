#include <bits/stdc++.h>

using namespace std;

#define MAX 505

int mapa[MAX][MAX];
int dist[MAX][MAX];
int l,c,xi=0,yi=0;
int dx[] = {1,-1,0,0,1,1,-1,-1,-2,-2,-2,2,2,2,-2,-2,2,2,0,0,1,1,-1,-1};
int dy[] = {0,0,-1,1,1,-1,-1,1,0,1,-1,-1,0,1,-2,2,2,-2,2,-2,2,-2,2,-2};
queue<pair<int,int>> fila;

bool valid(int x, int y){
    if(x<0||x>l||y<0||y>c||mapa[x][y]==0) return false;
    return true;
}

void bfs(int x,int y){
    memset(dist,-1,sizeof(dist));
    dist[x][y]=0;
    fila.push({x,y});

    while(!fila.empty()){
        int ax = fila.front().first, ay = fila.front().second;
        if(ax==l && ay==c) break;
        fila.pop();

        for(int i=0;i<24;i++){
            int nx = ax + dx[i], ny = ay + dy[i];

            if(valid(nx,ny)==false) continue;
            if(dist[nx][ny]==-1) {
                dist[nx][ny] = dist[ax][ay] + 1;
                fila.push({nx,ny});
            }
        }

    }
}

int main(){

    cin>>l>>c;

    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            cin>>mapa[i][j];
        }
    }

    bfs(1,1);

    cout<<dist[l][c];
    return 0;
}