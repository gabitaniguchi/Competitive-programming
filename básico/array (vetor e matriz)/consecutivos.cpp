#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tam, ans=0;
    
    scanf("%d", &tam);
    
    int v[tam];
    
    for(int i=0;i<tam;i++)
    {
        scanf("%d", &v[i]);
    }
    
    for(int i=0;i<(tam-2);i++)
    {
        if(v[i]==1 && v[i+1]==0 && v[i+2]==0) ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}