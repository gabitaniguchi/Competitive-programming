#include <bits/stdc++.h>
 
using namespace std;
 
deque<int> l, r;
#define int long long
#define ii pair<int,int>
 
int dp[20][2][2], a, b;
 
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
 
void intervalo(int a, int b){
    l.clear();
    r.clear();
    while(a){
        l.push_front(a%10);
        a/=10;
    }
 
    while(b){
        r.push_front(b%10);
        b/=10;
    }
    while(l.size() < r.size()) l.push_front(0);
    memset(dp, -1, sizeof dp);
}
 
int32_t main(){
 
    cin>>a>>b;
    intervalo(a,b);

    int resp = digit_dp(0,1,1, -1, 0);

    cout<<resp<<endl;


    return 0;
}