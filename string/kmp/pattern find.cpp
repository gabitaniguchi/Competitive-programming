#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s, int tam){
    vector<int> pi((int)s.size());
    pi[0] = 0;
    vector<int> ans;
    for(int i=1, j=0; i<(int)s.size();i++){
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
        if(pi[i]==tam) ans.push_back(i-2*tam+1);
    }
    return ans;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        string f, p;
        cin>>f>>p;
        string s = p + '*' + f;
        vector<int> ans = prefix_function(s, (int)p.size());
        if((int)ans.size()==0) cout<<"Not Found"<<endl;
        else{
            cout<<(int)ans.size()<<endl;
            for(auto x: ans) cout<<x<<" ";
            cout<<endl;
        }
        if(t) cout<<endl;
    }

    return 0;
}