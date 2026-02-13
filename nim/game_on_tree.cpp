#include <bits/stdc++.h>

using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define MAXN (int)(1e5+10)

int n,vis[MAXN], nimber[MAXN];
vector<int> g[MAXN];

void dfs(int x){
    vis[x] = 1;

    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        dfs(nxt);
        nimber[x] ^= (nimber[nxt]+1);
    }
}

int32_t main()
{_
    cin>>n;

    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    if(nimber[1]) cout<<"Alice\n";
    else cout<<"Bob\n";
}