#include <bits/stdc++.h>

using namespace std;

int main()
{
    int b,c, soma;
    
    scanf("%d %d", &b, &c);
    
    soma = b +c;
    
    if(soma%2 == 0)
    {
        printf("Bino\n");
    }
    else 
    {
        printf("Cino\n");
    }
    
    return 0;
}