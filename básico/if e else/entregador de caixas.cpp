#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a,b,c;
    int v;
    
    scanf("%d%d%d", &a, &b, &c);
    
    if(a==b&&b==c) v=3;
    else if((a<b&&b<c)||a+b<c) v=1;
    else if((a<b&&b>=c)||a+b>=c) v=2;

    printf("%d\n", v);    
    
    return 0;
    
}