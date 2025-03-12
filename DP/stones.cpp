#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10 )

char dp[MAX];
int n, k, coin[110];

int main(){

    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        cin>>coin[i];
        dp[coin[i]] = 'W';
    }
    
    sort(coin+1, coin+n+1);
    
    for(int sum=1; sum<coin[1]; sum++){
        dp[sum] = 'L';
    }
    
    for(int sum=1; sum<=k; sum++){
        for(int i=1; i<=n; i++){
            if(sum-coin[i]<=0 ||dp[sum]=='W') break;
            
            if(dp[sum-coin[i]]=='L'){
                dp[sum] = 'W';
                break;
            }
            
            else dp[sum] = 'L';
        }
    }
    
    if(dp[k]=='W') cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    
    return 0;
}