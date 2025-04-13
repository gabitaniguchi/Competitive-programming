/* Comprime uma string em número de repetições do periodo e periodo. A resposta é a soma dos dígitos
dessa compressão, ex: aaaabbb = 3a3b = 4

dp[i] -> menor custo para comprimir os primeiros i caracteres
a[i][j] -> custo de comprimir a subtring s[i ... j]
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define INF (int)(1e18+10)
#define MAX (int)(8010)
int a[MAX][MAX], dp[MAX];
string s;

vector <int> prefix_function(int ini, int fim){
    vector<int> pi((int)s.size());
    for(int i=ini+1, j=0; i<fim; i++){
        while(j>0 && s[i]!=s[j+ini]) j = pi[j-1+ini];
        if(s[i]==s[j+ini]) j++;
        pi[i] = j;
    }

    return pi;
}

int digits(int n){
    int ans = 0;
    while(n>0){
        ans++;
        n/=10;
    }
    return ans;


}

void pre_calcula(){
    for(int i=0; i<(int)s.size();i++){
        dp[i] = INF;
        vector<int> pi = prefix_function(i,(int)s.size());
        for(int j=i; j<(int)s.size();j++){
            if(i==j){
                a[i][j] = 2;
                continue;
            }
            int tam = j-i+1;
            int periodo = tam - pi[j];
            if(tam%periodo==0) a[i][j] = periodo + digits(tam/periodo);
            else a[i][j] = tam+1;
        }
    }
}

int32_t main(){

    cin>>s;
    
    pre_calcula();

    dp[0] = 2;
    for(int i=1; i<(int)s.size();i++){
        dp[i] = a[0][i];
        for(int j=0; j<i; j++){
            dp[i] = min(dp[i], dp[j] + a[j+1][i]);
        }
    }

    cout<<dp[(int)s.size()-1]<<endl;

    return 0;
}