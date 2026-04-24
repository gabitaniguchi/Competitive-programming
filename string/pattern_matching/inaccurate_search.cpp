#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

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
    string s, p;
    cin>>s>>p;
    int k; cin>>k;
    string s1 = p + "*" + s;
    string s2 = "";
    
    for(int i=p.size()-1; i>=0;i--) s2+=p[i];
    s2+="*";
    for(int i=s.size()-1; i>=0;i--) s2+=s[i];

    vector<int> z1 = z_function(s1);
    vector<int> temp = z_function(s2);
    vector<int> z2;

    for(int i=0;i<=p.size();i++) z2.push_back(temp[i]);
    for(int i=s.size()+p.size(); i>p.size(); i--) z2.push_back(temp[i]);

    set<int> ans;
    for(int i=p.size()+1; i<s1.size();i++){
        if((i+p.size())>s1.size()) break;
        if(z1[i]==p.size()) ans.insert(i-p.size());
        else if(z1[i]+k>=p.size()) ans.insert(i-p.size());
        else if(z2[i+p.size()-1]>=(p.size()-z1[i]-k)) ans.insert(i-p.size());
    }

    cout<<ans.size()<<endl;
    if(ans.size()>0) for(auto x: ans) cout<<x<<" ";
    cout<<endl;
}