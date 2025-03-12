#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e3+10)
int l, c;
int m[MAX][MAX], hist[MAX][MAX];
int ant[MAX][MAX], prox[MAX][MAX];
int ans = 0;

int main(){

    cin>>l>>c;

    for(int i=1;i<=l;i++){
        for(int j=1; j<=c; j++){
            cin>>m[i][j];
        }
    }

    for(int i=1; i<l; i++){
        for(int j=1; j<c;j++){
            int a = m[i][j];
            int b = m[i+1][j];
            int c = m[i][j+1];
            int d = m[i+1][j+1];

            if(a+d<=b+c) hist[i][j] = 1;
        }
    }

    for (int i=2; i<l; i++){
        for(int j=1; j<c; j++){
            if(hist[i][j]!=0) hist[i][j] += hist[i-1][j];
        }
    }

    for(int i=1; i<l; i++){
        hist[i][0] = -1;
        for(int j=1; j<c; j++){
            ant[i][j] = j-1;
            while(hist[i][j] <= hist[i][ant[i][j]]) ant[i][j] = ant[i][ant[i][j]];
        }
    }

    for(int i=1; i<l; i++){
        hist[i][c] = -1;
        for(int j=c-1; j>=1; j--){
            prox[i][j] = j+1;
            while(hist[i][j] <= hist[i][prox[i][j]]) prox[i][j] = prox[i][prox[i][j]];
        }
    }

    for(int i=1; i<l; i++){
        for(int j=1; j<c; j++){
            int largura = (j-ant[i][j]) + (prox[i][j] - j);
            int altura = hist[i][j] + 1;

            ans = max(ans, (altura)*(largura));
        }
    }

    cout<<ans<<endl;

    return 0;
}