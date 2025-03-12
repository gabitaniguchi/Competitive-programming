#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int x;
    
    scanf("%d", &x);
    
    if( x >= 1)
    {
        printf("positivo\n");
    }
    else if( x < 0)
    {
        printf("negativo\n");
    }
    else 
    {
        printf("nulo\n");
    }
    return 0;
}