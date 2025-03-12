#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,i, x, m2=0,m3=0,m4=0;
    
    scanf("%d", &N);
    
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &x);
        
        if (x%2 == 0)
        {
            m2 = m2 + 1;
        }
        if (x%3 == 0)
        {
            m3 = m3 + 1;
        }
        if (x%4 == 0)
        {
            m4 = m4 + 1;
        }
    }
    
    printf("%d\n%d\n%d\n", m2, m3, m4);
    
    return 0;
}