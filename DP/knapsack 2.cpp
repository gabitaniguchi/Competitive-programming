#include <bits/stdc++.h>

using namespace std;

#define MAXW (int)(1e9+10)
#define MAXN (int)(1e5+10)

int N, W, sum=0;
int v[110], w[110]; 
//dp[i][V] menor peso para pegar um valor V usando 1..i itens
int dp[110][MAXN];

int main(){

    cin>>N>>W;

    for(int i=1; i<=N; i++){
        cin>>v[i]>>w[i];
        sum+= v[i];
    }

    for(int i=0; i<=N; i++){
        for(int j=1; j<=sum; j++)
            dp[i][j] = MAXW;
    }

    // caso base dp[i][0] = 0;
    for(int i=1; i<=N; i++) dp[i][0] = 0;

    for(int i=1; i<=N; i++){
        for(int valor=1; valor<=sum; valor++){
            dp[i][valor] = dp[i-1][valor];

            if(v[i]<=valor)
                dp[i][valor] = min(dp[i][valor], dp[i-1][valor-v[i]] + w[i]);
                
        }
    }

    for(int valor=sum; valor>=1; valor--){
        if(dp[N][valor]<=W){
            cout<<valor<<endl;
            break;
        }
    }

    return 0;
}