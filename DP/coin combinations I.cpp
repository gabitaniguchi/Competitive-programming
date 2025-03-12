#include <bits/stdc++.h>

using namespace std;
#define mod (int)(1e9 + 7)
#define MAX (int)(1e6+10)
#define ll long long int

int n, x, coin[110];
ll dp[MAX];

int main(){

    cin>>n>>x;

    for(int i=1; i<=n; i++) cin>>coin[i];

    sort(coin+1, coin+1+n);

    dp[0] = 1;
    for(int i=1; i<=x; i++){
        for(int j=1; j<=n; j++){
            int temp = i - coin[j];
            //cout<<"t "<<temp<<endl;
            if(temp>=0) dp[i] += dp[temp]%mod;
        }
    }

    cout<<dp[x]%mod<<endl;

    return 0;
}