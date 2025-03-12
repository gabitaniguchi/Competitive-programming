#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
int n; //vértices
vector <int> g[MAX];
int dp[MAX];

int peso(int x, int pai){
    
	dp[x] = 1;
    
	for(int i=0;i<g[x].size();i++){
    	int next = g[x][i];
   	 
    	if(next == pai) continue;
    	dp[x] += peso(next, x);
   	 
	}
    
	return dp[x];
    
}


int main(){
    
	cin>>n;
    
	for(int i=1;i<=n;i++){
    	int a,b;
    	cin>>a>>b;
   	 
    	g[b].push_back(a);
	}
    
	peso(0,0);
	int ans = 0;
	
	for(int i=0;i<=n;i++){
    	if(g[i].size()<2) continue;
   	 
    	for(int j=1;j<g[i].size();j++){
        	int f1 = g[i][j-1];
        	int f2 = g[i][j];
       	 
        	if(dp[f1]!=dp[f2]){
            	ans = -1;
            	break;
        	}
    	}
   	 
    	if(ans == -1) break;
	}
    
	if(ans==0) cout<<"bem"<<endl;
	else cout<<"mal"<<endl;
    
	return 0;
}