#include <bits/stdc++.h>

using namespace std;

int main()
{
    char S[51], letra;
    int i, q=0, t;
    
    scanf("%s %c", S, &letra);
    
    t = strlen(S);
    
    for(i=0;i<t; i++)
    {
        if(S[i] == letra)
        {
            q++;
        }
    }
    
    printf("%d\n", q);
    
    return 0;
}