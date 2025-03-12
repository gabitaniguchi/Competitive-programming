#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(3e5 + 10)
int n, m, pai[MAX], len[MAX], tam[MAX];

pair<int,int> find (int x){
    if(pai[x]==x) return {x,0};
    pair<int,int> v = find(pai[x]);

    pai[x] = v.first;
    len[x] = (len[x] + v.second)%2;
    return {pai[x], len[x]};
}

void join(int a, int b){
    pair<int,int> x = find(a), y = find(b);

    if(tam[x.first] > tam[y.first]) swap(x,y);

    pai[x.first] = y.first;
    len[x.first] = (1 + x.second + y.second)%2;
    tam[y.first] += tam[x.first];
}

int main(){

    cin>>n>>m;

    for(int i=1; i<=n;i++){
        pai[i] = i;
        tam[i] = 1;
    }

    int ans = -1;

    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;

        join(a,b);
        if(len[find(a).first]==1 && ans==-1) ans = i;
    }

    cout<<ans<<endl;

    return 0;
}