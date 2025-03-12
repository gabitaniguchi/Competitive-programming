#include <bits/stdc++.h>

using namespace std;

int main()
{
    char S[51];
    int i, t;
    
    scanf("%s", S);
    
    t = strlen(S);
    
    printf("Vogais: ");
    
    for(i=0;i<t;i++)
    {
        if (S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
        {
            printf("%c", S[i]);
        }
    }
    printf("\nConsoantes: ");
    for(i=0;i<t;i++)
    {
        if(S[i]!='a'&&S[i]!='e'&&S[i]!='i'&&S[i]!='o'&&S[i]!='u')
        {
            printf("%c", S[i]);
        }
    }
    printf("\n");
    
    return 0;
}