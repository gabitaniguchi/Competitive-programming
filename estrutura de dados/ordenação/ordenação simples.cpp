#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    scanf("%d",&n);
    
    int v[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }
    
    sort(v,v+n);
   
    for(i=0;i<n;i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}