#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5 + 5)
#define ii pair<int, pair<int,int> > 

int n, m, pai[MAX], peso[MAX];
long long int ans = 0;
priority_queue<ii, vector<ii>, greater<ii>> fila;

int find(int x){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return;

    if(peso[x]>peso[y]) {
        pai[y] = x, peso[x]+=peso[y];
    }
    else {
        pai[x] = y;
        peso[y]+=peso[x];
    }
    
}
int main(){

    cin>>n>>m;

    while(m--){
        int a,b,w;
        cin>>a>>b>>w;

        fila.push({w, {a,b}});
    }

    for(int i=1;i<=n;i++){
        pai[i] = i;
        peso[i] = 1;
    }

    while(!fila.empty()){
        int d = fila.top().first;
        int a = fila.top().second.first;
        int b = fila.top().second.second;
        fila.pop();

        int pai1 = find(a);
        int pai2 = find(b);

        if(pai1!=pai2){
            ans += d;
            join(a,b);
        }
    }
    cout<<ans<<endl;

    return 0;
}