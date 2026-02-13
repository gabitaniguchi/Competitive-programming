#include <bits/stdc++.h>

using namespace std;
#define MAXN (int)(1e4)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
int dp[MAXN+10], vis[MAXN+10];

void precal(){
    dp[1] = dp[2] = 0;
    dp[3] = 1;
    
    for(int i=4; i<=10000; i++){
        for(int j=1; j<(i-j);j++){
            vis[dp[i-j]^dp[j]] = i;
        }
        int mex=0;
        while(vis[mex]==i) mex++;

        dp[i] = mex;
    }

}

int32_t main(){_

    int t; cin>>t;
    precal();

    for(int teste=1; teste<=t; teste++){
        int n; cin>>n;
        int ans=0;
        for(int i=1; i<=n; i++){
            int x;cin>>x;
            ans^= dp[x];
        }

        cout<<"Case "<<teste<<": ";

        if(ans) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;

    }

    return 0;
}