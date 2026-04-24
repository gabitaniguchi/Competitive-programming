#include <bits/stdc++.h>

using namespace std;
string s;

vector<int> z_function(){
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

vector<int> pi_function(){
    vector<int> pi(s.size());

    for(int i=1, j=0; i<(int)s.size(); i++){
        while(j>0 && s[j]!=s[i]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}

int main(){

    cin>>s;
    vector<int> pi = pi_function();
    vector<int> z = z_function();

    for(auto x: pi) cout<<x<<" ";
    cout<<endl;

    for(auto x:z) cout<<x<<" ";
    cout<<endl;

    return 0;
}