#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d,p1,p2,p3,e;
    
    scanf("%d %d %d %d ", &d, &p1, &p2, &p3);
    
    if((p1+p2+p3) <= d)
    {
        e = 3;
    }
    else if ( (p1+p2) <= d)
    {
       e = 2; 
    }
    else if ( (p1+p3) <= d)
    {
        e = 2;
    }
    else if ( (p2+p3) <= d)
    {
        e = 2;
    }
    else if ( p1 <= d)
    {
        e = 1;
    }
    else if ( p2 <= d)
    {
        e =1;
    }
    else if ( p3 <= d)
    {
        e = 1;
    }
    else 
    {
        e = 0;
    }
    printf("%d\n", e);
    
    return 0;
}
