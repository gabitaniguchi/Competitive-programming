#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int n, m, pai[MAX], peso[MAX];

int find(int x){
    if(pai[x]==x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x ==y) return;

    else if(peso[x] > peso[y]) pai[y] = x; 
    else if(peso[y] > peso[x]) pai[x] = y;

    else{
        pai[x] = y;
        peso[y]++;
    }
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++){
        pai[i] = i;
        peso[i] =1;
    }

    for(int i=1;i<=m;i++){
        int a,b;
        string s;
        cin>>s>>a>>b;

        if(s=="get") {
            if(find(a)==find(b)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

        else join(a,b);
        
    }

    return 0;
}