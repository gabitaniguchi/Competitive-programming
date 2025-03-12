#include <bits/stdc++.h>
 
using namespace std;
 
deque<int> l, r;
#define int long long
 
int dp[20][2][2], resta[9], k;
 
int digit_dp (int idx, int menor, int maior, int anterior, int significativo){
    // caso base: quando chega ao final
    if(idx >=(int)l.size()) return 1;
    int &resp = dp[idx][menor][maior];
    if(resp!=-1) return dp[idx][menor][maior];
    
    resp = 0;
    for(int d=(menor? l[idx]: 0); d<=(maior? r[idx]:9); d++){
        if(significativo==0 && d!=0) significativo=1;
        if(d==anterior && significativo==1) continue;
        int q = digit_dp(idx+1, menor&(d==l[idx]), maior&(d==r[idx]), d, significativo);
        dp[idx][menor][maior] += q;
    }
    return dp[idx][menor][maior];
}
 
int32_t main(){
 
    cin>>k;
    memset(dp, -1, sizeof(dp));
    memset(resta, k-1, sizeof(resta));

    if(k==1){
        cout<<9<<endl;
        return 0;
    }

    int resp = digit_dp(0,1,1, -1, 0);

    cout<<resp<<endl;


    return 0;
}