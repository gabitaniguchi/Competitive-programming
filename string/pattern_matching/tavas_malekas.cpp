#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MOD (int)(1e9+7)

int fast_exp(int base, int e){
    int ans = 1;
    while(e>0){
        if(e%2==1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e = e/2;

    }
    return ans;
}

vector<int> z_function(string &s){
    vector<int> z(s.size());
    int l=0, r=0;

    for(int i=1; i<(int)s.size();i++){
        if(i<r){
            z[i] = min(r-i, z[i-l]);
        }
        while(i+z[i]<(int)s.size() && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

int32_t main()
{_
    int n, m; cin>>n>>m;
    string s; cin>>s;
    cin.ignore();
    vector<int> z = z_function(s);
    int exp = n;
    bool pos=true;
    vector<int> idx(n+5);

    for(int i=1;i<=m;i++){
        cin>>idx[i];
        if(i>1 && (idx[i-1]+s.size()-1)>=idx[i]){
            int dif = idx[i]-idx[i-1];
            if(z[dif]<(s.size()-dif)) pos=false;
            exp-=((idx[i]+s.size()-1) - (idx[i-1]+s.size()-1));
        }
        else exp-=s.size();
    }

    if(!pos) cout<<0<<endl;
    else cout<<fast_exp(26, exp)<<endl;
    
}