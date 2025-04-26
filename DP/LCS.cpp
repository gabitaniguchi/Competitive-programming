#include <bits/stdc++.h>

using namespace std;

int dp[3010][3010];

int main(){

    string s,t;
    cin>>s>>t;

    dp[0][0] = 0;

    for(int i=0; i<=(int)s.size(); i++) dp[i][0] = 0;
    for(int j=0; j<=(int)t.size(); j++) dp[0][j] = 0;

    for(int i=1; i<=(int)s.size();i++){
        for(int j=1; j<=(int)t.size();j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;

            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i=(int)s.size(), j = (int)t.size();
    string ans = "";

    while(i!=0 && j!=0){
        if(dp[i-1][j]==dp[i][j]) --i;
        else if(dp[i][j-1]==dp[i][j]) --j;
        else{
            ans = t[j-1]+ans;
            --i;
            --j;
        }
    }
    cout<<ans<<endl;

    return 0;
}