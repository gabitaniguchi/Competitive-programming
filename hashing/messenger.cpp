#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(2e5+10)
#define MOD (int)(1e9)

int pot[MAX];
map<pair<int,char>,int> hashing;

void potencia(){
    pot[0] = 1;
    for(int i=1; i<=MAX; i++){
        pot[i] = pot[i-1]*31;
        pot[i]%=MOD;
    }
}

int calcula_hash (pair<int, char> s){
    int ans = 0;
    int c = s.second - 96;
    int n = s.first;
    ans = c*((pot[n]-1)/n-1);

    return hashing[s] = ans;
}

int main(){

    int n, m;
    cin>>n>>m;

    potencia();

    pair<int, char> t[n+5];
    pair<int, char> s[m+5];
    int pref_t[n+5];
    int pref_s[n+5];

    pref_t[0] = 0;
    pref_s[0] = 0;

    for(int i=1; i<=n; i++){
        int f;
        char c;
        cin>>f>>c;
        cin>>c;

        t[i] = {f,c};
        hashing[t[i]] = calcula_hash(t[i]);
        pref_t[i] = pref_t[i-1] + hashing[t[i]];
    }

    printf("\n");

    for(int i=1; i<=m; i++){
        int f;
        char c;
        cin>>f>>c;
        cin>>c;

        s[i] = {f,c};
        hashing[s[i]] = calcula_hash(s[i]);
        pref_s[i] = pref_s[i-1] + hashing[s[i]];
        printf("%d\n", pref_s[i]);
    }

    int ans = 0;

    for(int i=1; i<=(n-m+1); i++){
        printf("%d %d",t[i].first,s[i].first  );
        if(t[i].first<s[i].first || t[i+m-1].first<s[m].first) continue;
        if((pref_t[i+m-2]-pref_t[i]) == (pref_s[m]-pref_s[1])) ans++;
        printf("T: %d\n",pref_t[i+m-2]-pref_t[i] );
        printf("S: %d\n",pref_s[i]-pref_s[1] );
    }

    cout<<ans<<endl;

    return 0;
}