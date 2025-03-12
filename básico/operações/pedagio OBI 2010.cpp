#include <bits/stdc++.h>

using namespace std;

int main()
{
    int km,distp,custkm,custp,pedagio,estrada,total;
    
    scanf("%d %d %d %d", &km, &distp, &custkm, &custp);
    
    pedagio = (km/distp)*custp;
    estrada = km*custkm;
    total = pedagio+estrada;
    
    printf("%d\n", total);
    
    return 0;
}