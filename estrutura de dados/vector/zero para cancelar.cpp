#include <bits/stdc++.h>

using namespace std;

int main()
{
    int lim,n, soma = 0;
    
    scanf("%d", &lim);
    
    vector <int> seq;
    
    for(int i=1;i<=lim;i++)
    {
        scanf("%d", &n);
        
        if(n != 0) seq.push_back(n);
        else seq.pop_back();
        
    }
    
    int tam = (int)seq.size();
    
    for(int i=0;i<tam;i++)
    {
        soma = seq[i] + soma;
    }
    
    printf("%d\n", soma);
    
    return 0;
}