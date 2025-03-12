#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, h;

    scanf("%d %d", &n, &h);

    double hx[n+5];

    for(int i=1; i<n; i++){
        double intermed = static_cast<double>(i) / n;
        hx[i] = h*sqrtl(intermed);

        printf("%.12lf ", hx[i]);
    }

    printf("\n");

    return 0;
}