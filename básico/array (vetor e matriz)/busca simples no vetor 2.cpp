#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v[10];
    int x,i,r=0;
    
    for(i=0;i<10;i++)
    {
        scanf("%d", &v[i]);
        
    }
    
    scanf("%d", &x);
    
    for(i=0;i<10;i++)
    {
        if(v[i]==x)
        {
            r = r +1;
        }
    }
    
    if (r !=0)
    {
        printf("%d\n", r);
    }
    else 
    {
        printf("Mia x\n");
    }
    
     for(i=0;i<10;i++)
    {
        if(v[i]==x)
        {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    
    return 0;
}