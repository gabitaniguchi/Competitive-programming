#include <bits/stdc++.h>
 
using namespace std;
 
deque<int> l, r;
#define int long long
 
int dp[20][2][2], a, b, maior_prod=0;
vector<int> ans;
 
int digit_dp (int idx, int menor, int maior, vector<int> temp){
    
    int &resp = dp[idx][menor][maior];

    // caso base: quando chega ao final
    if(idx >=(int)l.size()) return temp[(int)temp.size()-1];

    if(resp!=-1) return dp[idx][menor][maior];
    
    resp = 0;
    for(int d=(menor? l[idx]: 0); d<=(maior? r[idx]:9); d++){
        temp.push_back(d);
        int q = digit_dp(idx+1, menor&(d==l[idx]), maior&(d==r[idx]), temp);
        temp.pop_back();
        dp[idx][menor][maior] = d*q;

        if(idx == 0){
            if(resp > maior_prod){
                maior_prod = resp;
                ans.clear();
                for(auto d: temp) ans.push_back(d);
                temp.clear();
            }
        }
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

    vector<int> t;

    digit_dp(0,1,1, t);

    for(auto d: ans) cout<<d;
    cout<<endl;


    return 0;
}