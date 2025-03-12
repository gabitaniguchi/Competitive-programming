#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,f1,f2,f3;
    
    scanf("%d %d %d", &m, &f1, &f2);
    
    f3= m - (f1+f2);
    
    if(f1 > f2 && f1 > f3)
    {
        printf("%d\n",f1);
    }
    else if( f2 > f1 && f2 > f3)
    {
        printf("%d\n",f2);
    }
    else
    {
    printf("%d\n", f3);
    }
    return 0;
}