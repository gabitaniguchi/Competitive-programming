#include <bits/stdc++.h>

using namespace std;
#define mod (int)(1e9 + 7)
#define MAX (int)(1e6+10)
int n, d=1, sum=0, prod=1, number=1;
pair<int,int> p[MAX];

int main(){

    cin>>n;

    for(int i=1;i<=n;i++){
        int b,exp;
        cin>>b>>exp;

        p[i] = {b,exp};
        d = d*(exp+1)%mod;
        number = number*pow(b,exp);
    }

    int temp=1, index=0,elevar=1;
    int metade;
    p[0] = {1,0};

    if(d%2==0) metade = d/2;
    else metade = (d+1)/2;

    for(int i=1;i<=metade;i++){
        sum += temp+(number/temp)%mod;
        prod = (prod*temp)%mod;
        prod = (prod*(number/temp))%mod;

        if(elevar<p[index].second){
            temp = temp*p[index].first;
            elevar++;
        }

        else {
            elevar = 1;
            index ++;
            temp = p[index].first;
        }
        
    }

    cout<<d<<" "<<sum<<" "<<prod<<endl;

    return 0;
}