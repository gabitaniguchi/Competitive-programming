#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e6+10)

vector<int> z(MAXN), pi(MAXN);
string s;

void pi_function(){
    for(int i=1, j=0; i<(int)s.size(); i++){
        while(j>0 && s[j]!=s[i]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}

void z_function(){
    int n = s.size();
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

int32_t main()
{_
    cin>>s;
    pi_function();
    z_function();

    int n = s.size();
    
    if(pi[n-1]==0) {
        cout<<"Just a legend"<<endl;
        return 0;
    }
    
    int suf_idx = n - pi[n-1];
    int mid_idx = 0;

    for(int i=1; i<n-1; i++){
        if(pi[i]>pi[mid_idx] && pi[i]<=pi[n-1]){
            mid_idx = i;
        }
    }

    bool pos=false;

    while(suf_idx<n && pi[mid_idx]>=1){
        if(pi[mid_idx] == z[suf_idx]){
            for(int i=suf_idx; i<n; i++) cout<<s[i];
            cout<<endl;
            pos=true;
            break;
        }

        suf_idx ++;
        while(z[suf_idx]!=(n-suf_idx) && suf_idx<n) suf_idx++;
        
        if(suf_idx < n){
            if(z[suf_idx] < pi[mid_idx]) mid_idx -= (pi[mid_idx])-z[suf_idx];
        }
    }

    if(!pos) cout<<"Just a legend"<<endl;
    
}

//abcaxyaxabca