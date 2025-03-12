#include <bits/stdc++.h>

using namespace std;
#define MAX 1010

int l, c;
int h[MAX][MAX], menor_prox[MAX][MAX], menor_ant[MAX][MAX], ans[MAX][MAX];
char mapa[MAX][MAX];

void menor_proximo(){
    for(int i=1; i<=l; i++){
        h[i][c+1] = -1;
        for(int j=c; j>=1; j--){
            menor_prox[i][j] = j+1;
            while(h[i][j] <= h[i][menor_prox[i][j]]) menor_prox[i][j] = menor_prox[i][menor_prox[i][j]];
        }
    }
}

void menor_anterior(){
    for(int i=1; i<=l; i++){
        h[i][0] = -1;
        for(int j=1; j<=c; j++){
            menor_ant[i][j] = j-1;
            while(h[i][j] <= h[i][menor_ant[i][j]]) menor_ant[i][j] = menor_ant[i][menor_ant[i][j]];
        }
    }
}

int main(){

    cin>>l>>c;
    int um = 0;

    for(int i=1; i<=l; i++){
        for(int j=1; j<=c; j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='.') um++;
        
            if(mapa[i][j]=='*') h[i][j] = 0;
            else if(i==1) h[i][j] = 1;
            else h[i][j] = h[i-1][j]+1;
        }
    }
    menor_anterior();
    menor_proximo();

    for(int i=1; i<=l; i++){
        for(int j=1; j<=c; j++){
            int largura = (j - menor_ant[i][j]) + (menor_prox[i][j] - j) - 1;
            int altura = h[i][j];

            for(int i=1; i<=largura; i++) ans[i][altura] ++;
        }
    }

    ans[1][1] = um;

    for(int i=1; i<=l;i++){
        for(int j=1;j<=c;j++){
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}