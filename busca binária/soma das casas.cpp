#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int casas, soma;
int v[MAX];

int busca (int x){
    int inicio = 1;
    int fim = casas;
    
    while(inicio<=fim){
        int meio = (inicio+fim)/2;
        
        if(v[meio]==x) return 1;
        
        else if(v[meio]>x) fim = meio-1;
        
        else inicio = meio+1;
    }
    
    return -1;
}

int main(){
    
    cin>>casas;
    
    for(int i=1;i<=casas;i++){
        cin>>v[i];
    }
    
    cin>>soma;
    
    for(int i=1;i<=casas;i++){
        if(busca(soma - v[i]) == 1){
            printf("%d %d\n",v[i],soma-v[i]);
            break;
        }
        
    }
    
    
    return 0;
}