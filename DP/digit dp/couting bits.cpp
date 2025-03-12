#include <bits/stdc++.h>

using namespace std;
#define int long long
deque<int> lim;
int dp[55][2], sum[55][2];
#define ii pair<int,int>

ii digit_dp (int pos, int maior){

    if(pos >= (int)lim.size()) return {0,1};
    int &resp = dp[pos][maior];
    if(resp!=-1) return {resp, sum[pos][maior]};

    resp = 0;
    int t = maior?lim[pos]:1;
    cout<<t<<endl;
    cout<<pos<<endl;

    for(int d=0; d<=maior?lim[pos]:1; d++){
        int nmaior = maior;
        if(d < lim[pos]) nmaior = 0;
        auto[s, q] = digit_dp(pos+1, nmaior);
        resp += d*q + s;
        sum[pos][maior] += q;
    }
    cout<<resp<<sum[pos][maior]<<endl;
    return {resp, sum[pos][maior]};
}

void binary(int n){
    while(n>0){
        int bit = n&1;
        lim.push_front(bit);
        n = n>>1;
    }

    cout<<"number ";
    for(auto d: lim) cout<<d;
    cout<<endl;
}

int32_t main(){

    int n;
    cin>>n;
    binary(n);

    memset(dp, -1, sizeof(dp));
    memset(sum, 0, sizeof(sum));

    cout<<digit_dp(0, 1).first<<endl;

    return 0;
}