#include <bits/stdc++.h>

using namespace std;
#define MAX 1010

int l, c, mapa[MAX][MAX];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void mancha (int x, int y){
    mapa[x][y] = -1;

    for(int i=0; i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(mapa[nx][ny]==1) mancha(nx, ny);
    }
}

int main(){

    cin>>l>>c;

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            cin>>mapa[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<l;i++){
        for(int j=0; j<c; j++){

            if(mapa[i][j]==1){
                ans++;
                mancha(i,j);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}