#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)

int n,m, tam = 1, pai[MAX], peso[MAX];

int find(int x){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return;
    
    if(peso[x]>peso[y]){
        pai[y] = x;
        peso[x] +=peso[y];
        tam = max(tam, peso[x]);
    }

    else{
        pai[x] = y;
        peso[y] += peso[x];
        tam = max(tam, peso[y]);
    }

}

int main(){

    cin>>n>>m;
    int comp=n;

    for(int i=1;i<=n;i++){
        peso[i] = 1;
        pai[i] = i;
    }

    while(m--){
        int a, b;
        cin>>a>>b;

        int pai1 = find(a);
        int pai2 = find(b);

        if(pai1!=pai2){
            join(a,b);
            comp--;
        }
        
        cout<<comp<<" "<<tam<<endl;

    }

    return 0;
}