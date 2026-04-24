#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

int pai[MAXN], peso[MAXN];

int find(int x){
    if(x == pai[x]) return x;
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

int32_t main()
{_
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        pai[i]=i;
        peso[i]=1;
    }

    vector<pair<int,pair<int,int>>> edges;

    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }

    sort(edges.begin(), edges.end());
    int ans=0;
    for(auto [c, p]: edges){
        auto [a,b] = p;
        if(find(a)!=find(b)) {
            join(a,b);
            ans+=c;
        }
    }
    int comp = find(1);
    for(int i=2;i<=n;i++){
        if(find(i)!=comp){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }

    cout<<ans<<endl;
    return 0;
}