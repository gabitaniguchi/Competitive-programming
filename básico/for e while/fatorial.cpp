#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,r;
    
    scanf("%d", &n);
    
    if(n==0)
    {
        printf("1\n");
    }
    
    else
    {
    for(i=1;i<= n-1;i++)
    {
        if (i==1)
        {
            r = n*i;
        }
        else
        {
            r = r*i;
        }
    }
    
    printf("%d\n", r);
    }
    
    return 0;
    
}