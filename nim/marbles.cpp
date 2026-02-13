#include <bits/stdc++.h>
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
int dp[110][110];
int vis[1000];

void precomp(){
    dp[0][0] = 999;
    for(int i=1;i<=100;i++) {
        dp[i][0] = 999;
        dp[0][i] = 999;
        dp[i][i] = 999;
    }
    int t=1;
    for(int i=1; i<=100;i++){
        for(int j=1;j<i;j++){
            //diagonal
            for(int k=1;i-k>=0 && j-k>=0;k++) vis[dp[i-k][j-k]]=t;
            //cima e lado
            for(int k=i-1;k>=0;k--) vis[dp[k][j]]=t;
            for(int k=j-1;k>=0;k--) vis[dp[i][k]]=t;
            
            int mex=0;
            while(vis[mex]==t) mex++;
            
            dp[i][j] = dp[j][i] = mex;
        
            t++;
        }

    }
}

int32_t main()
{_

    precomp();

    // for(int i=0;i<=10;i++){
    //     for(int j=0;j<=10;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    int n, ans=0;
    cin>>n;
    bool win=false;

    for(int i=1;i<=n;i++){
        int l,c;
        cin>>l>>c;

        if(l==0 || c==0 ||l==c) win=true;
        ans^= dp[l][c];
    }
    if(ans || win) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
}