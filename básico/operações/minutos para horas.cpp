#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M, h,m;
    
    scanf("%d", &M);
    
    h = M/60;
    m = M%60;
    
    printf("%d\n%d\n", h, m);
    
    return 0;

}