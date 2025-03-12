#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
 
    long long int v[n+5], pref[n+5], menor[n+5], maior=-10e9;
 
    menor[0] = 0;
    pref[0] = 0;
 
    for(int i=1;i<=n;i++){
        cin>>v[i];
 
        if(i==1) pref[i] = v[i];
        else pref[i] = pref[i-1] + v[i];        
        menor[i] = min(menor[i-1], pref[i-1]);
    }
 
    for(int i=1;i<=n;i++){
        maior = max(maior, pref[i]-menor[i]);
    }
 
    cout<<maior<<endl;
}