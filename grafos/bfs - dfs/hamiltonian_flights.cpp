#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MOD (int)(1e9+7)

vector<int> g[25];
int n, m, ans=0;

void hamilton(int mask, int at){
    if(mask==(pow(2,n)-1)) {
        ans++;
        ans%=MOD;
        return;
    }

    for(auto nxt: g[at]){
        if((1<<(nxt-1)) & mask) continue;
        hamilton((mask|(1<<(nxt-1))), nxt);
    }
}
int dp[1<<21][22];

int32_t main()
{_
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    

    for(int mask=0)
    
}