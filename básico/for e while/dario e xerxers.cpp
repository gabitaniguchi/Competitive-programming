#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, D, X, vd=0, vx=0;
    
    scanf("%d", &n);
    
    for(i=1;i<=n;i++)
    {
        scanf("%d %d", &D, &X);
        if (D == 0)
        {
            if ( X == 1)
            {
                vd = vd + 1;
            }
            else if( X == 2)
            {
                vd = vd + 1;
            }
            else if( X == 3)
            {
                vx = vx + 1;
            }
            else if ( X == 4)
            {
                vx = vx +1;
            }
        }
        else if (D == 1)
        {
            if ( X == 0)
            {
                vx = vx + 1;
            }
            else if ( X == 2)
            {
                vd = vd + 1;
            }
            else if ( X == 3)
            {
                vd = vd + 1;
            }
            else if ( X == 4)
            {
                vx = vx + 1;
            }
        }
        else if (D == 2)
        {
            if ( X == 0)
            {
               vx = vx + 1;
            }
            else if ( X == 1)
            {
                vx = vx + 1;
            }
            else if ( X == 3)
            {
                vd = vd + 1;
            }
            else if ( X == 4)
            {
                vd = vd + 1;
            }
        }
        else if (D == 3)
        {
            if ( X == 0)
            {
                vd = vd + 1;
            }
            else if ( X == 1)
            {
                vx = vx + 1;
            }
            else if ( X == 2)
            {
                vx = vx + 1;
            }
            else if ( X == 4)
            {
                vd = vd + 1;
            }
        }
        else if ( D ==4)
        {
            if (X == 0)
            {
                vd = vd + 1;
            }
            else if ( X == 1)
            {
                vd = vd + 1;
            }
            else if ( X == 2)
            {
                vx = vx + 1;
            }
            else if ( X == 3)
            {
                vx = vx + 1;
            }
        }
    }
    if ( vx > vd)
    {
        printf ( "xerxes\n");
    }
    else 
    {
        printf ( "dario\n");
    }
    return 0;
}