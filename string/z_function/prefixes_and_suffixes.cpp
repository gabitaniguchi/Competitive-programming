#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

int z[MAXN];
vector<int> freq;

void z_function(string &s){
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
}

int busca(int x){
    int i=0, f=freq.size()-1, ans=0;

    while(i<=f){
        int m=(i+f)/2;

        if(freq[m]>=x) f = m-1;
        else {
            ans = max(ans, m+1);
            i=m+1;
        }
    }
    return freq.size() - ans;
}

int32_t main()
{_
    string s; cin>>s;
    z_function(s);
    vector<pair<int,int>> ans;

    for(int i=0; i<s.size();i++) {
        if(z[i]>0) freq.push_back(z[i]);
    }

    sort(freq.begin(), freq.end());

    for(int i=s.size()-1; i>=1;i--){
        if(z[i]!= s.size()-i) continue;

        int qnt = busca(z[i]);
        ans.push_back({s.size()-i, qnt+1});
    }

    ans.push_back({s.size(), 1});

    cout<<ans.size()<<endl;
    for(auto [idx, qnt]: ans){
        cout<<idx<<" "<<qnt<<endl;
    }

}