#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e6+10)

int dp[MAX], x;
int const inf = 1e9+10;

int main(){

    cin>>x;

    for(int i=1; i<=x; i++) dp[i] = inf;

    dp[0] = 0;
    for(int sum=1; sum<=x; sum++){
        string s = to_string(sum);
        for(char c: s){
            int digit = c - '0';
            if(digit != 0){
                dp[sum] = min(dp[sum], dp[sum-digit] + 1);
            }
        }
    }

    cout<<dp[x]<<endl;

    return 0;
}