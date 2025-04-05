#include <bits/stdc++.h>

using namespace std;

string s, p;
vector<int> pi;

int prefix_function(string t){
    int ans = 0;
    vector<int> pi(t.size());
    for(int i=1, j=0; i<(int)t.size(); i++){
        while(j>0 && t[j]!=t[i]) j = pi[j-1];
        if(t[i] == t[j]) j++;
        pi[i] = j;
        if(pi[i] == (int)p.size()) ans++;
    }
    return ans;
}

int main(){

    cin>>s>>p;
    string t = p + '*' + s;
    cout<<prefix_function(t)<<endl;;

    return 0;
}