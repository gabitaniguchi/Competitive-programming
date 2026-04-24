#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

vector<int> prefix_function(string p){
    vector<int> pi(p.size());
    for(int i=1, j=0; i<(int)p.size(); i++){
        while(j>0 && p[j]!=p[i]) j = pi[j-1];
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main()
{_
    string s, t;
    cin>>s>>t;
    vector<int> pi = prefix_function(t+"*"+s);
    int ans=0, last=0;

    for(int i=t.size()+1; i<pi.size(); i++){
        if(pi[i]==t.size() && i-last>=t.size()){
            ans++;
            last=i;
        } 
    }

    cout<<ans<<endl;
}