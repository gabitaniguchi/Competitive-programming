#include <bits/stdc++.h>

using namespace std;

int main(){

    int d, m;
    cin>>d>>m;

    double hip = d * sqrt(2);
    int temp = m/hip;
    double x = temp;
    double y = (m - x*hip);
    
    y *= sqrt(2);
    x *= d;
    y /= 2;
    x += y;
    if(temp%2 == 1 && m-temp*hip!=0) y = d - y;

    printf("%.10lf %.10lf\n", x, y);

    return 0;
}