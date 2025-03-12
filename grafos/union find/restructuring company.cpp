#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5 + 10)

int pai[MAX], peso[MAX], n, m;

int find(int x){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    int px = find(x), py = find(y);

    if(px==py) return;

    if(peso[px]>peso[py]) pai[py] = px;
    else if(peso[py]>peso[px]) pai[px] = py;

    else{
        pai[px] = py;
        peso[py]++;
    }
}

int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        pai[i] = i;
        peso[i] = 1;
    }

    while(m--){
        int q, a, b;
        cin>>q>>a>>b;

        if(q==1) join(a,b);
        else if(q==2){
            int temp = a;
            while(temp<b){
                join(temp,temp+1);
                temp++;
            }
        }

        else{
            if(find(a)==find(b)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}