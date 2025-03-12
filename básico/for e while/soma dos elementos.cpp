#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v,n, m=0, i=0;
    
    scanf("%d", &v);
    
    while( i < v)
    {
        scanf("%d", &n);
        m = m + n;
        
        i++;
    }
    
    printf("%d\n", m);
    
    return 0;
}