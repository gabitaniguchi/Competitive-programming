#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5+10)

int n, v[MAX], esq[MAX];

int main(){

    cin>>n;

    for(int i=1;i<=n;i++) cin>>v[i];

    esq[1] = 0;

    for(int i=2;i<=n;i++){
        esq[i] = i-1;
        while(v[i] <= v[esq[i]]){
            esq[i] = esq[esq[i]];
        }
    }

    for(int i=1;i<=n;i++) cout<<esq[i]<<" ";
    cout<<endl;

    return 0;
}