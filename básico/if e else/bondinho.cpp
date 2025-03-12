#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,m,total;
    
    scanf("%d %d", &a, &m);
    
    total= a+m;
    
    if(total <= 50)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }
    
    return 0;
}