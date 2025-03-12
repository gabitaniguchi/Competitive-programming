#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A=0, B=0, i=1, n, I;
    
    scanf("%d", &n);
    
    while ( i <= n)
    {
        scanf ( "%d", &I);
        if(I == 1 )
        {
            if ( A == 0)
            {
                A = 1;
            }
            else if ( A == 1)
            {
                A = 0;
            }
        }
        else if ( I == 2 && A == 1)
        {
            A = 0;
        }
        else if ( I ==2 && A ==0)
        {
            A = 1;
        }
        if (I ==2 && B ==0)
        {
            B = 1;
        }
        else if (I == 2 && B == 1)
        {
            B = 0;
        }
        i ++;
    }
    printf("%d\n%d\n", A, B);
    
    return 0;
}