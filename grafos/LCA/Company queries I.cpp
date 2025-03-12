#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(2e5 + 10)
#define MAXLOG 19

int n, q, up[MAX][MAXLOG];

int main(){

    cin>>n>>q;

    for(int i=2; i<=n; i++){
        cin>>up[i][0];
    }

    for(int j=1; j<MAXLOG; j++){
        for(int i=2; i<=n; i++){  
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int x, k;
        cin>>x>>k;

        for(int i=0; i<MAXLOG; i++){
            if(k & (1<<i)) x = up[x][i];
        }

        if(x==0) x=-1;
        cout<<x<<endl;
    }

    return 0;
}