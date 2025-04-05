#include <bits/stdc++.h>

using namespace std;

string s, p;

vector<int> prefix_function(string p){
    vector<int> pi(p.size());
    for(int i=1, j=0; i<(int)p.size(); i++){
        while(j>0 && p[j]!=p[i]) j = pi[j-1];
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        vector<int> pi((int)s.size());
        pi = prefix_function(s);
        int k = (int)s.size() - pi[(int)s.size()-1];
        if((int)s.size()%k==0) cout<<k<<endl;
        else cout<<(int)s.size()<<endl;
        if(t) cout<<endl;

    }

    return 0;
}