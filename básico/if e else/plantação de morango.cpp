#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l1, c1, l2, c2, a1, a2;
    
    scanf("%d %d %d %d", &l1, &c1, &l2, &c2);
    
    a1 = l1*c1;
    a2 = l2*c2;
    
    if(a1 > a2)
    {
        printf("%d\n", a1);
    }
    else
    {
        printf("%d\n", a2);
    }
    return 0;
}