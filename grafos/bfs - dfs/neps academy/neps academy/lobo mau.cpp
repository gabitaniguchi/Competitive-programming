#include <bits/stdc++.h>

using namespace std;

#define MAX 260

int l,c, lobo=0, ovelha=0, fora_pasto=0;
char mapa[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool fora_limite(int x, int y){
    if(x==0 || y==0 || x==l-1 || y==c-1) return true;
    return false;
}

bool borda (int x, int y){
    if(x<0 || x>=l || y<0 || y>=c) return true;
    return false;
}

void dfs(int x, int y){
    if(mapa[x][y] == 'v') lobo++;
    else if(mapa[x][y] == 'k') ovelha++;
    
    mapa[x][y] = '*';

    for(int i=0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if(mapa[nx][ny]=='#' || mapa[nx][ny]=='*' || borda(nx,ny)) continue;
        if(mapa[nx][ny]=='.' && fora_limite(nx,ny)) fora_pasto = 1;
        dfs(nx,ny);
    }
}

int main(){

    cin>>l>>c;

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            cin>>mapa[i][j];
        }
    }

    int ans_l=0, ans_o=0;

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
    
            if(mapa[i][j]!='*' && mapa[i][j]!='#'){
                dfs(i,j);
                if(fora_pasto==0) {
                    if(ovelha>lobo) ans_o += ovelha;
                    else ans_l += lobo;
                }

                ovelha=0;
                lobo=0;
                fora_pasto=0;
            }
        }
    }

    cout<<ans_o<<" "<<ans_l<<endl;

    return 0;
}