#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e6+10)

string s, p;
vector<int> pi;
int automato[26][MAX];

vector<int> prefix_function(string p){
    vector<int> pi(p.size());
    for(int i=1, j=0; i<(int)p.size(); i++){
        while(j>0 && p[j]!=p[i]) j = pi[j-1];
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void Automato_KMP (){
    // o primeiro caractere da string s leva a sair do estado 0
    automato[p[0]-'a'][0] = 1;
    for(int c=0; c<26; c++){
        for(int i=1; i<=(int)p.size(); i++){
            automato[c][i] = c == p[i]-'a'? i+1 : automato[c][pi[i-1]];
        }
    }
}

int matching(){
    int ans = 0, estado=0;
    for(int i=0; i<(int)s.size(); i++){
        estado = automato[s[i]-'a'][estado];
        if(estado == (int)p.size()) ans++;
    }

    return ans;
}

int main(){

    cin>>s>>p;
    pi = prefix_function(p);
    Automato_KMP();
    cout<<matching()<<endl;

    return 0;
}