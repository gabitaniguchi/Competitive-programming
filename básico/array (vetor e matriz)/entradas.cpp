#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int tam, x;
    
    scanf("%d %d", &tam, &x);
    
    double d_oeste, d_leste, d_total , d_min = tam;
    
    double capitais[x];
    
    for(int i=0;i<x;i++)
    {
        scanf("%lf", &capitais[i]);
    }
    
    sort(capitais,capitais+x);
    
    for(int i=0;i<x;i++)
    {
       if(i==0) 
       {
           d_oeste = capitais[i];
       }
       
       else 
       {
           d_oeste = (capitais[i] - capitais[i-1])/2;
       }
       
       if(i==x-1) 
       {
           d_leste = tam - capitais[i];
       }
       
       else 
       {
           d_leste = (capitais[i+1] - capitais[i])/2;
       }
       
       d_total = d_leste + d_oeste; 
       
       if (d_total < d_min) d_min = d_total;
       
    }
    
    printf("%.2lf\n", d_min);
    
    return 0;
}