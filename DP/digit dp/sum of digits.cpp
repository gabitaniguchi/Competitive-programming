#include <bits/stdc++.h>
 
using namespace std;
 
deque<int> l, r;
#define int long long
#define ii pair<int,int>
 
int dp[10][2][2], qtd[10][2][2], a, b;
 
ii digit_dp (int idx, int menor, int maior){
    // caso base: quando chega ao final
    if(idx >=(int)l.size()) return {0,1};
    int &resp = dp[idx][menor][maior];
    if(resp!=-1) return {resp, qtd[idx][menor][maior]};
    
    resp = 0;
    for(int d=(menor? l[idx]: 0); d<=(maior? r[idx]:9); d++){
        auto[s, q] = digit_dp(idx+1, menor&(d==l[idx]), maior&(d==r[idx]));
        resp += d*q + s;
        qtd[idx][menor][maior] += q;
    }
    return {resp, qtd[idx][menor][maior]};
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
    memset(qtd, 0, sizeof qtd);
}
 
int32_t main(){
 
    while(true){
        cin>>a>>b;
        if(a==-1 && b==-1) break;
 
        intervalo(a,b);
 
        int resp = digit_dp(0,1,1).first;
 
        cout<<resp<<endl;
    }
 
    return 0;
}