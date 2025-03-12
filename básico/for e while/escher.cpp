#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int h[n], j=n-2, t;
    int falhou=0;
    
    for(int i=0;i<n;i++) scanf("%d", &h[i]);
    
    int s = h[0]+h[n-1];
    
    t = (n/2)+1;
    
    for(int i=1;i<t;i++)
    {
        if(s != (h[i]+h[j]))
        {
            printf("N\n");
            falhou = 1;
            break;
        }
        j--;
    }
    
    if(falhou == 0)  printf("S\n");
    
    return 0;
}