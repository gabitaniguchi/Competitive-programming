#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int dp[MAX];
vector <int> g[MAX];
int n;

int dfs (int x, int p){
	
	dp[x] = 1;
	
	for(int i=0;i<g[x].size();i++){
		int atual = g[x][i];
		
		if(atual!=p) dp[x] += dfs(atual, x);
	}
	return dp[x];
} 

int main(){
   
    cin>>n;
	
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}	
	
	dfs(1,1);
	
	int ans = 100010;
	
	for(int i=2;i<=n;i++){
	    
	    int cidade_1 = dp[1] - dp[i];
	    int cidade_2 = dp[i];
	    
	    int maior = max(cidade_1, cidade_2);
	    int menor = min(cidade_1, cidade_2);
	    
	    ans = min (ans, maior - menor);
	}

	cout<<ans<<endl;
	
	return 0;
}