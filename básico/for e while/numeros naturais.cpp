#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, s = 0;
    
    scanf("%d", &n);
    
    for(i=1;i<=n;i++)
    {
        s = s + i;
    }
    
    printf("%d\n", s);
    
    return 0;
}