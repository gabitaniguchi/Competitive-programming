#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10)
#define MOD (int)(1e9)

int pot[MAX];
map<string,int> hashing;

void potencia(){
    pot[0] = 1;
    for(int i=1; i<=MAX; i++){
        pot[i] = pot[i-1]*37;
        pot[i]%=MOD;
    }
}

int calcula_hash (string s){
    if(hashing.find(s)!=hashing.end()) return hashing[s];
    int ans = 0;
    for(int i=0; i<(int)s.size(); i++){
        int x = s[i] - 96;
        ans += (x*pot[i])%MOD;
        ans%=MOD;
    }

    return hashing[s] = ans;
}

int main(){

    int n;
    cin>>n;

    string a,b;
    cin>>a>>b;

    calcula_hash(a);
    calcula_hash(b);

    




    return 0;
}