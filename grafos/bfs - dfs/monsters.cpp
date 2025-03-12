#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e3 + 10)

char mapa[MAX][MAX];
pair<char, int> lava[MAX][MAX];
int l,c, xi, yi, xf, yf;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue <pair<int,int>> fila;
stack<char> caminho;
map<pair<int,int>, pair<int,int>> pai; 

bool valid (int x, int y){
    if(x<1||x>l||y<1||y>c|| mapa[x][y]=='#') return false;
    return true;
}

void path(int x, int y){
    pair<int,int> atual;
    atual = {x,y};

    while(true){
        if(atual.first==xi && atual.second==yi) break;
        char pos;
        int nx = atual.first, ny = atual.second;
        int px = pai[{nx,ny}].first, py = pai[{nx,ny}].second;
        
        if(px == nx-1) pos='D';
        else if(py == ny-1) pos='R';
        else if(px == nx+1) pos='U';
        else if(py == ny+1) pos='L';

        caminho.push(pos);
        atual = pai[{nx,ny}]; 
    }
}

int main(){

    cin>>l>>c;
    bool ans = false;

    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            cin>>mapa[i][j];
            lava[i][j] = {'N', -1};

            if(mapa[i][j]=='M') fila.push({i,j}), lava[i][j] = {'M', 0};
            else if(mapa[i][j]=='A') xi=i, yi=j, lava[i][j] = {'A', 0};
        }
    }

    fila.push({xi,yi});

    if(xi==1||xi==l||yi==1||yi==c){
        ans = true;
        cout<<"YES"<<endl;
        cout<<"0"<<endl;
        return 0;
    }

    while(!fila.empty() && ans!=true){
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();

        if(x==1||x==l||y==1||y==c){
            if(lava[x][y].first=='A') {
                ans = true;
                xf=x, yf=y;
                break;
            }
        }

        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];

            if(!valid(nx,ny)) continue;

            if(lava[x][y].first == 'M'){
                if(lava[nx][ny].second == -1){
                    lava[nx][ny].first = 'M';
                    lava[nx][ny].second = lava[x][y].second + 1;
                    fila.push({nx,ny});
                    pai[{nx,ny}] = {x,y};
;                }

                else if(lava[nx][ny].second>lava[x][y].second + 1){
                    lava[nx][ny].first = 'M';
                    lava[nx][ny].second = lava[x][y].second + 1;
                    fila.push({nx,ny});
                    pai[{nx,ny}] = {x,y};
                }
            }

            else if(lava[x][y].first == 'A'){
                if(lava[nx][ny].second == -1){
                    lava[nx][ny].first = 'A';
                    lava[nx][ny].second = lava[x][y].second + 1;
                    fila.push({nx,ny});
                    pai[{nx,ny}] = {x,y};
                }

                else if(lava[nx][ny].first=='M' && lava[nx][ny].second>lava[x][y].second + 1){
                    lava[nx][ny].first = 'A';
                    lava[nx][ny].second = lava[x][y].second + 1;
                    fila.push({nx,ny});
                    pai[{nx,ny}] = {x,y};
                }
            }
        }

    }

    if(ans == false) printf("NO\n");
    else{
        cout<<"YES"<<endl;
        path(xf,yf);
        cout<<caminho.size()<<endl;

        while(!caminho.empty()){
            cout<<caminho.top();
            caminho.pop();
            if(caminho.empty()) cout<<endl;
        }

    }

    return 0;
}