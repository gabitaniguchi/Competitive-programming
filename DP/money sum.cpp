#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10)

int n, coin[110], sum=0;
int dp[MAX];

int main(){
    
    cin>>n;
    set<int> resp;
    
    for(int i=1; i<=n; i++){
        cin>>coin[i]; 
        sum += coin[i];
    } 
    
    sort(coin+1, coin+1+n);
    dp[0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=sum; j>=coin[i]; j--){
            if(dp[j-coin[i]]==1){
                dp[j] = 1;
                resp.insert(j);
            }
        }
    }
    
    cout<<resp.size()<<endl;
    for(auto x: resp) cout<<x<<" ";
    cout<<endl;
    
    return 0; 
}