#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
int s, h[MAX], dp[MAX];
const int INF = 2e9;

int frog (int n){

    if(dp[n]!=-1) return dp[n];

    if(n==1) return dp[n] = 0;

    int res = INF;

    for(int i=1; i<=2;i++){

        if((n-i)<1) continue;

        res = min(res, frog(n-i) + abs(h[n]-h[n-i]));
    }

    return dp[n] = res;
}

int main(){

    cin>>s;

    for(int i=1;i<=s;i++){

        cin>>h[i];
    }

    memset(dp, -1, sizeof dp);

    cout<<frog(s)<<endl;

    return 0;
}
