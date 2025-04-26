#include <bits/stdc++.h>

using namespace std;
#define int long long

double exp (double base, int e){
    double ans =1.0;
    while(e>0){
        if(e%2==1) ans = (ans*base);
        base = (base*base);
        e = e/2;

    }
    return ans;
}

int32_t main(){

    int m, n;
    cin>>m>>n;
    double esperanca = 0;

    for(int i=1; i<=m; i++){
        double p=0;
        double b1 = i, b2 =(i-1);
        p += exp((b1/m), n);
        p -= exp(b2/m, n);
        esperanca += p*i;
    }

    printf("%.15lf\n", esperanca);
    return 0;
}