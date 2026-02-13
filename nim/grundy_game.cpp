#include <bits/stdc++.h>

using namespace std;
#define MAXN (int)(1e6)

int dp[MAXN+10];

void precal(){
    dp[1] = dp[2] = 0;
    dp[3] = 1;
    
    for(int i=4; i<=2000; i++){
        set<int> s;
        for(int j=1; j<(i-j);j++){
            s.insert(dp[i-j]^dp[j]);
        }
        int mex=0;
        while(s.find(mex)!=s.end()) mex++;

        dp[i] = mex;
    }

    for(int i=2001; i<=MAXN;i++) dp[i] = 1;
}

int main(){

    int t; cin>>t;
    precal();

    while(t--){
        int n; cin>>n;
        if(dp[n]) cout<<"first"<<endl;
        else cout<<"second"<<endl;

    }

    return 0;
}