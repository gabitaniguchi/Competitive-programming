#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)

int vis[MAXN];
int esq=0, dir=0;
vector<int> g[MAXN];

void dfs(int x, int target){
    vis[x] = 1;
    esq++;
    
    for(auto nxt: g[x]){
        if(nxt==target) return;
        if(vis[nxt]) continue;
        dfs(nxt, target);
    }
}

int32_t main()
{_
    int n, t;
    cin>>n>>t;
    vector<int> folha;

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(g[i].size()==1) folha.push_back(i);
    }

    int x;cin>>x;

    if(x==folha[0] || x==folha[1]) esq = n-1;
    else{
        dfs(folha[0], x);
        dir = n - esq-1;
    }

    if(esq%2==1 || dir%2==1) cout<<"Ron"<<endl;
    else cout<<"Hermione"<<endl;

    
}