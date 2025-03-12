#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(3*1e5 + 10)

int n, m, pai[MAX], peso[MAX], menor[MAX], maior[MAX]; 

int find(int x){
    if(pai[x]==x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return;
    
    if(peso[x]>peso[y]){
        menor[x] = min(menor[x], menor[y]);
        maior[x] = max(maior[x], maior[y]);
        pai[y] = x;
        peso[x] += peso[y];
    }

    else{
        menor[y] = min(menor[y], menor[x]);
        maior[y] = max(maior[y], maior[x]);
        pai[x] = y;
        peso[y]+=peso[x];
    }
    
}

int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        pai[i] = i;
        peso[i] = 1;
        menor[i] = i;
        maior[i] = i;
    }

    for(int i=1;i<=m;i++){
        string s;
        int a,b;
        cin>>s;

        if(s=="union") {
            cin>>a>>b;
            join(a,b);
        }
        else{
            cin>>a;
            int conj = find(a);

            cout<<menor[conj]<<" "<<maior[conj]<<" "<<peso[conj]<<endl;
        }
    }



    return 0;
}