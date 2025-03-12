#include <bits/stdc++.h>

using namespace std;

int main() {
    int b, i=1, l, c, quebrados=0;
    
    scanf ("%d", &b);
    
    while (i<=b) {
        scanf ("%d %d", &l, &c);
        if (l>c) {
            quebrados = quebrados + c;
        }
        i++;
    }
    
    printf ("%d\n", quebrados);
    
    return 0;
}