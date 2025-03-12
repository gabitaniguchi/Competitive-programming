#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    
    scanf("%d %d", &x, &y);
    
    if(x == 0 || y == 0)
    {
        printf("eixos\n");
    }
    else if (x>0 && y>0)
    {
        printf("Q1\n");
    }
    else if (x<0 && y>0)
    {
        printf("Q2\n");
    }
    else if (x<0 && y<0)
    {
        printf("Q3\n");
    }
    else if(x>0 && y<0)
    {
        printf("Q4\n");
    }
    
    return 0;
}