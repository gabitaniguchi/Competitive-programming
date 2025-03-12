#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)
int n,m;
vector<int> g[MAX];
stack<pair<int,int>> ans;
int vis[MAX];

void dfs (int x){
    vis[x] = 1;

    for(auto next: g[x]){
        if(vis[next]==1) continue;
        dfs(next);
    }
}

int main(){

    cin>>n>>m;

    while(m--){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int last;

    for(int i=1;i<=n;i++){
        if(vis[i]!=1) {
            
            dfs(i);
            if(i!=1) ans.push({last,i});
            last = i; 
        }
    }

    cout<<ans.size()<<endl;
    while(!ans.empty()){
        auto temp = ans.top();
        cout<<temp.first<<" "<<temp.second<<endl;
        ans.pop();
    }

    return 0;
}