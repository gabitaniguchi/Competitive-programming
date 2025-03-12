#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p,i,s=0,c=0;
    
    scanf("%d", &n);
    
    for(i=1; i<=n; i++)
    {
        scanf("%d", &p);
        if ( p < 50)
        {
            s = s + 1;
        }
        else if ( p >= 50 && p < 85)
        {
            c = c + 1;
        }
    }
    printf("%d %d\n", s,c);
    
    return 0;
}