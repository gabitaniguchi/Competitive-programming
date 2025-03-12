#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j;
    
    scanf("%d", &n);
    
    int fila[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d", &fila[i]);
    }
    
    int s;
    
    scanf("%d",&s);
    
    int sairam[s];
    
    for(i=0;i<s;i++)
    {
        scanf("%d", &sairam[i]);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<s;j++)
        {
            if (fila[i] == sairam[j])
            {
                break;
            }
            else if(j == s-1)
            {
                printf("%d ", fila[i]);
            }
        }
    }
    
    printf("\n");
   
    return 0;
}