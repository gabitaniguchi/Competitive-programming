#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int q[n][n];
    int l,c;
    int soma=0,total,falhou=0;
    
    for(l=0;l<n;l++)
    {
        for(c=0;c<n;c++)
        {
            scanf("%d", &q[l][c]);
        }
    }
     for(l=0;l<n;l++)
    {
        soma += q[l][l];
    }
    total = soma, soma =0;
    for(l=0;l<n;l++)
    {
      soma += q[l][n-1-l];
    }
    if(total!=soma)
    {
        falhou = 1;
    }
    for(l=0;l<n;l++)
    {
        soma = 0;
        for(c=0;c<n;c++)
        {
            soma += q[l][c];
        }
        if(total!= soma)
        {
            falhou =1;
        }
    }
    for(c=0;c<n;c++)
    {
        soma = 0;
        for(l=0;l<n;l++)
        {
            soma += q[l][c];
        }
        if(total!= soma)
        {
            falhou =1;
        }
    }
    if(falhou == 0)
    {
        printf("%d\n", total);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}