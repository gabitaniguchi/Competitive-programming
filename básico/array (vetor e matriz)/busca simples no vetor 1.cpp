#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v[10];
    int i,x;
    
    for(i=0;i<10;i++)
    {
        scanf("%d", &v[i]);
    }
    
    scanf("%d", &x);
    
    for(i=0;i<10;i++)
    {
        if (v[i] == x)
        {
            printf("SIM\n");
            break;
        }
        else if(i == 9)
        {
          printf("NAO\n");
        }
    }
    
    return 0;
}