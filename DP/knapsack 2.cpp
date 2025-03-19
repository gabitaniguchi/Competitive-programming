#include <bits/stdc++.h>

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX (int)(105)
#define MAX_SUM (int)(1e5+10)
#define INF (int)(1e15+10)

using namespace std;

int n, w, sum=0;
int valor[MAX], peso[MAX], dp[MAX][MAX_SUM];

// encontrar a menor soma de pesos para um item com valor V
int knapsack(int i, int v){
    if(v==0) return 0; 
    if(i>n) return INF;
    if(dp[i][v] != -1) return dp[i][v];

    int ans = INF;
    ans = min(ans, knapsack(i+1, v));
    if(v - valor[i]>=0) {
        ans = min(ans, peso[i] + knapsack(i+1, v-valor[i]));
    }
    
    return dp[i][v]=ans;
}

int32_t main(){_ 

    cin>>n>>w;

    for(int i=1; i<=n; i++){
        cin>>peso[i]>>valor[i];
        sum+= valor[i];
    }

    memset(dp, -1, sizeof(dp));

    for(int i=sum; i>=0; i--){
        if(knapsack(1,i) <= w){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}