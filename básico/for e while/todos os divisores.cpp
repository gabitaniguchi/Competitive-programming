#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, x;
    
    scanf("%d", &x);
    
    for(i=1; i <= x; i++)
    {
        if (x%i == 0)
        {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    
    return 0;
}