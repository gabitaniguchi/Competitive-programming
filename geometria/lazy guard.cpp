#include <bits/stdc++.h>

using namespace std;

int main(){

    int q;
    cin>>q;

    int i=1, f=10000, ans;

    while(i<=f){
        int m = (i+f)/2;
        if(m*m == q){
            ans = m;
            break;
        }

        else if(m*m < q) {
            ans = m;
            i = m+1;
        } 

        else f = m-1;
    }

    if(abs(ans*ans - q) > abs((ans+1)*(ans+1)-q)) ans++; 

    int p = ans*4;
    if(q> ans*ans){
        int sobra = (q - ans*ans)/ans;
        if(q - ans*ans - sobra*ans !=0) sobra++;
        p+= 2*sobra;
    }

    cout<<p<<endl;



    return 0;
}