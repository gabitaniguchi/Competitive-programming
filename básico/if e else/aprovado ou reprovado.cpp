#include <bits/stdc++.h>

using namespace std;

int main()
{
    float a,b, media;
    
    scanf("%f %f", &a, &b);
    
    media= (a+b)/2;
    
    if( media >= 7)
    {
        printf("Aprovado\n");
    }
    else if(media < 7 && media >= 4)
    {
        printf("Recuperacao\n");
    }
    else 
    {
        printf("Reprovado\n");
    }
    
    return 0;
}