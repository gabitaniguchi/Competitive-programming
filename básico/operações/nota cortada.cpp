#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,B;
    
    scanf("%d %d", &B, &T);
    
    if (((T+B)*70)/2 > 5600 )
    {
        printf("1\n");
    }
    else if(((T+B)*70)/2 < 5600 )
    {
        printf("2\n");
    }
    else 
    {
        printf("0\n");
    }
    return 0;
}