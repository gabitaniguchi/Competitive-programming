#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, n; 
    float r;
    double raiz;
    
    scanf(" %d", &n);
    
    for(i=1; i<=n; i++)
    {
        scanf("%f", &r);
        raiz = sqrt(r);
        printf("%.4lf\n", raiz);
    }
    printf("\n");
    
    return 0;
}