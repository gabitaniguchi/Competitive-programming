#include <bits/stdc++.h>

using namespace std;

int fun(int a,int b)
{
    return a>b;
}

int main()
{
    int q;
    scanf("%d", &q);
    int c[q+1];
    int total = 0;
    
    for(int i=0;i<q;i++)
    {
        scanf("%d", &c[i]);
    }
    sort(c, c+q, fun);
    
     for(int i=0;i<q;i++)
    {
        if((i+1)%3==0) continue;
        else total+= c[i];
    }
    
    printf("%d\n", total);
    
    return 0;
}