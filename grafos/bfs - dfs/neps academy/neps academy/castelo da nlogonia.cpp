#include <bits/stdc++.h>

using namespace std;

#define MAX 110

vector <int> g[MAX]; //lista de adjacência 
int vis[MAX];
int cor[MAX];
int n, q, t=1;// vértices, queries e testes 

bool colorindo (int begin, int end, int c){
    
    bool serve = false;
    
    vis[begin] = t;
    
    if(begin == end){
        cor[begin] = c;
        return serve = true;
    }
    
    for(int i=0;i<g[begin].size();i++){
        int next = g[begin][i];
        
        if(vis[next]!=t){
            if(colorindo(next,end,c)){
                cor[begin] = c;
                serve = true;
            }
        }
    }
    
    return serve;
}


int main(){
    
    cin>>n>>q;
    
    for(int i=1; i<n; i++){
        
        int a,b;
        cin>>a>>b;
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(int i=1;i<=q;i++){
        
        int comeca, fim, pinte;
        cin>>comeca>>fim>>pinte;
        
        colorindo(comeca,fim,pinte);
        t++;
        
    }
    
    for(int i=1;i<=n;i++){
        cout<<cor[i];
        if(i<n) cout<<" ";
        else cout<<endl;
    }
    
    return 0;
}