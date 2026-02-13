#include <bits/stdc++.h>

using namespace std;

vector<int> pi_function(string& s){
    vector<int>pi(s.size());
    for(int i=1, j=0; i<s.size();i++){
        while(j>0 && s[j]!=s[i]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){

    int t, teste=0;
    freopen("period.in", "r", stdin);
	freopen("period.out", "w", stdout);
    while(cin>>t && t!=0){
        string s;
        cin>>s;
        teste++;

        vector<int> pi = pi_function(s);

        cout<<"Test case #"<<teste<<endl;

        for(int i=2; i<=t;i++){
            int k = i-pi[i-1];
            if(i%k==0 && i!=k) cout<<i<<" "<<i/k<<endl;
        }
    }
    return 0;
}
