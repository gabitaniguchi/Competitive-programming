#include <bits/stdc++.h>

using namespace std;

string s, p;
vector<int> pi;

vector<int> prefix_function(string p){
    vector<int> pi(p.size());
    for(int i=1, j=0; i<(int)p.size(); i++){
        while(j>0 && p[j]!=p[i]) j = pi[j-1];
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int matching(){
    int ans = 0;
    for(int i=0, j=0; i<(int)s.size(); i++){
        while(j>0 && p[j] != s[i]) j = pi[j-1];
        if(p[j] == s[i]) j++;
        if(j==(int)p.size()-1) ans++;
    }

    return ans;
}

int main(){

    cin>>s>>p;
    p += '*';
    pi = prefix_function(p);
    cout<<matching()<<endl;

    return 0;
}