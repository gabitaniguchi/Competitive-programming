#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v[10],i;
    
    for(i=0;i<10;i++)
    {
        scanf("%d", &v[i]);
        {
            if(v[i]%2==0)
            {
                printf("%d ", v[i]);
            }
        }
    }
    
    printf("\n");
    
    for(i=0;i<10;i++)
    {
       if(v[i]%2!=0)
       {
         printf("%d ", v[i]); 
       }
    }
    printf("\n");
    
    return 0;
}