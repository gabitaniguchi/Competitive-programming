#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m[3][3];
    int l,c,sl=0;

    for(l=0;l<3;l++)
    {
        for(c=0;c<3;c++)
        {
            scanf("%d", &m[l][c]);
            sl = sl + m[l][c];
            if(l==0 && c==2)
            {
                printf("Linha 0: %d\n", sl);
                sl = 0;
            }
            else if (l==1 && c==2)
            {
                printf("Linha 1: %d\n", sl);
                sl = 0;
            }
            else if (l==2 && c==2)
            {
                printf("Linha 2: %d\n", sl);
                sl = 0;
            }
        }
    }
    
    return 0;
}