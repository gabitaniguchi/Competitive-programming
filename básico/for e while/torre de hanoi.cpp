#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int torre[n][n], linha[n], coluna[n];
    int l,c, soma;
    int maior=0;
    
    for(l=0;l<n;l++)
    {
        for(c=0;c<n;c++)
        {
            scanf("%d", &torre[l][c]);
        }
        linha[l]=0;
        coluna[l]=0;
    }
    
    for(l=0;l<n;l++)
    {
        for(c=0;c<n;c++)
        {
        linha[l] += torre[l][c];
        coluna[l] += torre[c][l];
        }
    }
    for(l=0;l<n;l++)
    {
       for(c=0;c<n;c++)
       {
           soma = linha[l] + coluna[c] - (2*torre[l][c]);
           if(soma>maior)
           {
               maior = soma;
           }
       }
    }
    printf("%d\n", maior);
    
    return 0;
}