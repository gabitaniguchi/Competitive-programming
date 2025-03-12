#include <bits/stdc++.h>

using namespace std;

#define MAX (int) (1e6 + 10)

int n, q, maior[MAX], pai[MAX], tam[MAX];

int find(int x){
    if (x == pai[x]) return x;
    return find(pai[x]);
}

void join( int x, int y){
    int X = find(x), Y = find(y);

    if(tam[X]<tam[Y]) swap(X,Y);

    pai[Y] = pai[X];
    tam[X] += tam[Y];
    maior[X] = max(maior[Y], maior[X]);
}


int32_t main(){

    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;

    for(int i=1;i<=n+1;i++){
        pai[i] = i;
        maior[i] = i;
        tam[i] = 1;
    }

    char op;
    int a;

    while(q--){
        cin>>op>>a;

        if(op == '-') join(a, a+1);
        else{
            cout<<(maior[find(a)] > n ? -1 : maior[find(a)]) << endl;
        }
    }


    return 0;
}