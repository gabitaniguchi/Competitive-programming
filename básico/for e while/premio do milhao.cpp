#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i=1, dias , a ,r=0, R=0;
    
    scanf("%d", &dias);
    
    while( i <= dias )
    {
        i ++;
        R ++;
        scanf("%d", &a);
        r = r + a;
        
        if ( r >= 1000000) 
        {
            i = dias + 1;
        }
        
    }
    
    printf("%d\n", R);
    
    return 0;
}