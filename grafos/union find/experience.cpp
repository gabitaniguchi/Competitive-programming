#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(2e5 + 10)
#define ll long long int

int n, q, pai[MAX], tam[MAX]; 
ll power[MAX], add[MAX];

int find (int x){
    if(pai[x]==x) return x;
    return find(pai[x]);
}

ll poder(int x){
    if(pai[x] == x) return power[x] + add[x];
    return power[x] + add[x] + poder(pai[x]);
}

void join(int x, int y){
    int a = find(x), b = find(y);

    if(a==b) return;
    if(tam[a]<tam[b]) swap(a,b);

    pai[b] = a;
    add[b] -= add[a];
    tam[a] += tam[b];
}

int main(){

    cin>>n>>q;

    for(int i=1; i<=n; i++){
        power[i] = 0;
        tam[i] = 1;
        pai[i] = i;
    }

    while(q--){
        string s;
        int a, b;
        cin>>s;

        if(s=="join"){
            cin>>a>>b;

            join(a,b);
        }

        else if(s=="add"){
            cin>>a>>b;

            add[find(a)] += b;
        }

        else{
            cin>>a;
            cout<<poder(a)<<endl;
        }

    }

    return 0;
}

