#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e6+10)
#define INF (int)(1e9+10)

int dp[MAX];

int remove(int x, string s){
  cout<<"x "<<x<<endl;
  if(dp[x]!=-1) return dp[x];

  dp[x] = INF;

  for(int i=0; i<(int)s.size();i++){
    int digit = s[i]-'0';
    if(digit==0) continue;
    if(x-digit<0) continue;
    dp[x] = min(dp[x], remove(x-(s[i]-48), to_string(x-(s[i]-48)))+1);
  }

  return dp[x];
}

int main(){

  string s;
  int n=0, d=1;;

  cin>>s;

  for(int i=(int)s.size()-1; i>=0;i--){
    int dig = s[i]-48;
    n+= d*dig;
    d*=10;
  }

  for(int i=10; i<=n; i++){
    dp[i] = -1;
  }

  for(int i=1; i<=9; i++){
    dp[i] = 1;
  }

  dp[0]=0;

  cout<<remove(n, s)<<endl;

  return 0;
}