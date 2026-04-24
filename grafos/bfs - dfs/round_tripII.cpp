#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
int n,m, vis[MAX], ciclo=-1;
int final, semifinal;
vector<int> g[MAX], ans;
map<int,int> pai;

int dfs(int x, int p){
    vis[x] = 1;
    pai[x] = p;

    if(ciclo != 1){
        for(int i=0;i<(int)g[x].size();i++){
            int next = g[x][i];

            if(vis[next]==1){
                final = next;
                semifinal = x;
                ciclo = 1;
                break;
            }
        
            else if(vis[next]==0) dfs(next,x);
        }
    }
   
    vis[x] = 2;
    return ciclo;
}

int main(){
   
    cin>>n>>m;
   
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
       
        g[a].push_back(b);
    }
   
    for(int i=1;i<=n;i++){
        ciclo = dfs(i,0);

        if(ciclo==1) break;
    }
    
    if(ciclo == -1){
        printf("IMPOSSIBLE\n");
    }
   
    else{
        ans.push_back(final);
        ans.push_back(semifinal);
       
        int x = semifinal;
       
        while(x != final){
            x = pai[x];
            ans.push_back(x);
        }
       
        printf("%d\n", (int)ans.size());
       
        for (int i=(int)ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
       
    }
   
    return 0;
}
