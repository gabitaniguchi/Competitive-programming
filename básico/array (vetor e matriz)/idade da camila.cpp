#include <bits/stdc++.h>

using namespace std;

int main()
{
    int idade[3];
    
    for (int i=0;i<3;i++)
    {
        scanf("%d", &idade[i]);
    }
    
    sort(idade,idade+3);
    
    printf("%d\n", idade[1]);
    
    return 0;
}