#include <bits/stdc++.h>

using namespace std;

int main()
{
    int lim, n1,n2,res;
    char oper;
    
    scanf("%d %d %c %d", &lim, &n1, &oper, &n2);
    
    if(oper == '+')
    {
        res = n1+n2;
        if(res<=lim)
        {
            printf("OK\n");
        }
        else
        {
            printf("OVERFLOW\n");
        }
    }
    else
    {
        res = n1*n2;
        if(res<=lim)
        {
            printf("OK\n");
        }
        else
        {
            printf("OVERFLOW\n");
        }
    }
    return 0;
}