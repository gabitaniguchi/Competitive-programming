#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c, A,B,C;
    
    scanf("%d %d %d", &a, &b, &c);
    
    A = a/2;
    B = b/3;
    C = c/5;
    
    if(A==B && B ==C)
    {
        printf("%d\n",A);
    }
    else if(A<=B && A<=C )
    {
        printf("%d\n",A);
    }
    else if ( B<=A && B<=C)
    {
        printf("%d\n",B);
    }
    else 
    {
        printf("%d\n",C);
    }
    return 0;
}