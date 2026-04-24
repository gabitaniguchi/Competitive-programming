#include <bits/stdc++.h>

using namespace std;
#define MAXN (int)(2e5+10)

vector<pair<int,string>> g[MAXN];
map<int, string> binario;
string ans="";

void eulerian(int x, string b){
    while(!g[x].empty()){
        auto [nxt, bit] = g[x].back();
        g[x].pop_back();
        eulerian(nxt,bit);
    }
    ans += b;
}

int main(){
    int n; cin>>n;

    if(n==1){
        cout<<"10"<<endl;
        return 0;
    }
    
    for(int mask=0; mask<=(pow(2,n-1)-1); mask++){
        string s = "";
        for(int k=n-2; k>=0; k--){
            if((1<<k) & mask) s+="1";
            else s+="0";
        }

        binario[mask] = s;
        int x = mask>>(n-2)==1? (1<<(n-1)): 0;
        int num = (mask<<1)^(x);
        g[mask].push_back({num, "0"});
        g[mask].push_back({num+1,"1"});
    }
    eulerian(0,"0");
    for(int i=n-2;i>=1;i--) ans+="0";

    cout<<ans<<endl;
}
