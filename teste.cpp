#include <bits/stdc++.h>
using namespace std;

string s;

vector <int> prefix_function(int ini, int fim){
    vector<int> pi((int)s.size());
    for(int i=ini+1, j=0; i<=fim; i++){
        while(j>0 && s[i]!=s[j+ini]) j = pi[j-1+ini];
        if(s[i]==s[j+ini]) j++;
        pi[i] = j;
    }

    return pi;
}

int main(){

    cin>>s;

    int t;
    cin>>t;

    while(t--){
        int ini,fim;
        cin>>ini>>fim;
        vector<int> pi = prefix_function(ini,fim);
        for(int i=ini; i<=fim; i++) cout<<pi[i]<<" ";
        cout<<endl;
    }

    return 0;
}