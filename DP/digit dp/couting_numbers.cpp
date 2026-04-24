#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(20)

int dp[MAXN][2][2];
string l,r, temp;
queue<pair<int,pair<int,int>>> fila;

void func(int i, int maior, int menor){
    while(!fila.empty()){
        auto [i, m] = fila.front();
        fila.pop();
        auto[maior, menor] = m;
    }
    if(i>=(l.size())) return;
    cout<<i<<" "<<maior<<" "<<menor<<endl;
    if(i>0){
        cout<<"dp["<<i-1<<"][1][1] = "<<dp[i-1][1][1]<<endl;
        cout<<"dp["<<i-1<<"][0][1] = "<<dp[i-1][0][1]<<endl;
        cout<<"dp["<<i-1<<"][1][0] = "<<dp[i-1][1][0]<<endl;
    }

    if(maior==1 && menor==1){
        dp[i][1][1] += dp[i-1][1][1]*9;
        func(i+1, 1,1);
    }

    else if(maior==1 && menor==0){
        if(r[i-1]==r[i]) return;
        // pega o r[i]
        dp[i][1][0] = dp[i-1][1][0];
        func(i+1, 1, 0);
        
        // pega < r[i]
        int temp = r[i] - '0';
        if(r[i]>r[i-1]) temp--;
        dp[i][1][1] += dp[i-1][1][0] * temp;
        if(temp>0) func(i+1,1,1);
    }

    else if(maior==0 && menor==1){
        if(i>0 && i>=(r.size()-temp.size()) && l[i-1]==l[i]) return;
        // pega o l[i]
        dp[i][0][1] = 1;
        func(i+1,0,1);
        // pega > l[i]
        int temp = (9-l[i]-'0');
        if(i>0 && l[i]<l[i-1]) temp--;
        dp[i][1][1] += temp;
        if(temp>0) func(i+1,1,1);
    }

    else{
        if(i>0 && i>=(r.size()-temp.size()) && (l[i]==l[i-1] || r[i]==r[i-1])) return;
        if(l[i]==r[i]){
            dp[i][0][0]=1;
            func(i+1,0,0);
        }
        else{
            dp[i][0][1] = 1;
            func(i+1,0,1);
            dp[i][1][0] = 1;
            func(i+1,1,0);

            int temp = r[i]-'0'-(l[i]-'0');
            if(i>0 && l[i-1]>l[i]&&l[i-1]<r[i]) temp--;
            dp[i][1][1] += temp;
            if(temp>0) func(i+1,1,1);
        }
    }
}

int32_t main()
{_
    l = "";
    cin>>temp>>r;

    if(temp==r){
        for(int i=1; i<r.size();i++){
            if(r[i]==r[i-1]){
                cout<<0<<endl;
                return 0;
            }
        }
        cout<<1<<endl;
        return 0;
    }

    for(int i=1; i<=(r.size()-temp.size()); i++) l+="0";
    l+=temp;

    func(0, 0, 0);

    int ans = dp[l.size()-1][1][0] + dp[l.size()-1][1][1];

    cout<<ans<<endl;
}