#include <bits/stdc++.h>

using namespace std;

int main()
{
    char S[16];
    int i,t;
    
    scanf("%s", S);
    
    t = strlen(S);
    
    for(i=0;i<t;i++)
    {
        if(S[i]=='A'||S[i]=='B'||S[i]=='C')
        {
            printf("2");
        }
        else if(S[i]=='D'||S[i]=='E'||S[i]=='F')
        {
            printf("3");
        }
        else if(S[i]=='G'||S[i]=='H'||S[i]=='I')
        {
            printf("4");
        }
        else if(S[i]=='J'||S[i]=='K'||S[i]=='L')
        {
            printf("5");
        }
        else if(S[i]=='M'||S[i]=='N'||S[i]=='O')
        {
            printf("6");
        }
        else if(S[i]=='P'||S[i]=='Q'||S[i]=='R'||S[i]=='S')
        {
            printf("7");
        }
        else if(S[i]=='T'||S[i]=='U'||S[i]=='V')
        {
            printf("8");
        }
        else if(S[i]=='W'||S[i]=='X'||S[i]=='Y'||S[i]=='Z')
        {
            printf("9");
        }
        else
        {
            printf("%c", S[i]);
        }
    }
    printf("\n");
    
    return 0;
}