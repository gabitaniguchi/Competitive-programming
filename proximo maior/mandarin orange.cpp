#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e4+10)

int n, orange[MAX], menor_ant[MAX], menor_prox[MAX];

void menor_anterior(){
    menor_ant[1] = 0;
    for(int i=1; i<=n; i++){
        menor_ant[i] = i-1;
        while(orange[i]<=orange [menor_ant[i]]) menor_ant[i] = menor_ant[menor_ant[i]];
    }
}

void menor_proximo (){

    orange[n+1] = 0;
    for(int i=n; i>=1; i--){
        menor_prox[i] = i+1;
        while(orange[i]<=orange[menor_prox[i]]) menor_prox[i] = menor_prox[menor_prox[i]];
    }

}

int main(){

    cin>>n;

    for(int i=1; i<=n; i++) cin>>orange[i];

    menor_anterior();
    menor_proximo();

    int ans = 0;

    for(int i=1; i<=n; i++){
        int temp = ((i-menor_ant[i]) + (menor_prox[i]-i) - 1)*orange[i];
        ans = max(temp,ans); 
    }

    cout<<ans<<endl;

    return 0;
}