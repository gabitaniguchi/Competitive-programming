#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define MAXLOG (31)

int up[MAXN][MAXLOG];

int main()
{_
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        up[i][0] = x;
    }

    for(int k=1; k<MAXLOG;k++){
        for(int i=1;i<=n;i++){
            up[i][k] = up[up[i][k-1]][k-1];
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        int ans = a;

        for(int k=0;k<MAXLOG;k++){
            if((1<<k)&b) ans = up[ans][k];
        }
        cout<<ans<<endl;
    }
    
}