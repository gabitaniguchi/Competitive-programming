#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(2e5 + 10)
#define MAXLOG 19

int n, q, up[MAX][MAXLOG];
int tin[MAX], tout[MAX], t=0;
vector<int> g[MAX];

void dfs(int x){
    tin[x] = t;

    for(auto next: g[x]){
        t++;
        dfs(next);
    }

    t++;
    tout[x] = t;
}

bool anc(int a, int b){
    if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
    return false;
}

int LCA (int a, int b){
    if(anc(a,b)) return a;
    if(anc(b,a)) return b;

    for(int i=MAXLOG-1; i>=0; i--){
        if(!anc(up[a][i], b) && up[a][i]!=0) a = up[a][i];
    }
    return up[a][0];
}

int main(){

    cin>>n>>q;

    for(int i=2; i<=n; i++){
        cin>>up[i][0];

        g[up[i][0]].push_back(i);
    }

    dfs(1);

    for(int j=1; j<MAXLOG; j++){
        for(int i=1; i<=n; i++){  
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int a, b;
        cin>>a>>b;

        cout<<LCA(a,b)<<endl;
    }

    return 0;
}