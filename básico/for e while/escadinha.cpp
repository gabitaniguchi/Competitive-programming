#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int v[N];
    int s = 1;
    
    for(int i=0;i<N;i++) 
    {
        scanf("%d", &v[i]);
    }
    
    int d = v[1]-v[0];
    
    for(int i=2;i<N;i++)
    {
        if(d != (v[i]-v[i-1]))
        {
            s++;
            d = v[i]-v[i-1];
        }
    }
    
    printf("%d\n", s);
    
    return 0;
}