#include<bits/stdc++.h>

using namespace std;

#define MAX 1005
char g[MAX][MAX], dir[MAX][MAX];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int vis[MAX][MAX];
int l,c,xi,yi;
queue<pair<int,int>> f;
stack<char> caminho;

void direcao(int x,int y,int nx, int ny){
    if(nx==x+1) dir[nx][ny] = 'D';
    else if(nx==x-1) dir[nx][ny] = 'U';
    else if(ny==y+1) dir[nx][ny] = 'R';
    else if(ny==y-1) dir[nx][ny] = 'L';
}

bool bfs(int xi, int yi){
    
    f.push({xi,yi});

    while(!f.empty())
    {
        int x = f.front().first;
        int y = f.front().second;
        f.pop();
        vis[x][y] = 1;

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||nx>=l||ny<0||ny>=c||vis[nx][ny]==1||g[nx][ny]=='#') continue;

            if(g[nx][ny]=='.'){
                f.push({nx,ny});
                direcao(x,y,nx,ny);
            }

            else if(g[nx][ny]=='B'){
                direcao(x,y,nx,ny);
                int a=nx, b=ny;
                
                while(true){
                    caminho.push(dir[a][b]);

                    if(dir[a][b]=='U') a++;
                    else if(dir[a][b]=='D') a--;
                    else if(dir[a][b]=='R') b--;
                    else if(dir[a][b]=='L') b++;

                    if(g[a][b]=='A') break;
                }
                return true;
            }
        }
    }

    return false;
}

int main(){
    cin>>l>>c;

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){

            cin>>g[i][j];
            if(g[i][j]=='A'){
                xi = i;
                yi = j;
            }
        }
    }

    if(bfs(xi,yi)) {
        printf("YES\n");
        cout<<caminho.size()<<endl;

        while(!caminho.empty()){
            cout<<caminho.top();
            caminho.pop();
        }
        cout<<endl;
    }

    else printf("NO\n");

    return 0;
}