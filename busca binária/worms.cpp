#include<bits/stdc++.h>

using namespace std;

#define MAX 100010
int n, k,v[MAX];

int busca(int x){
    int inicio = 1;
    int fim = n;
    int ans = n+1;

    while(fim>=inicio){
        int meio = (inicio+fim)/2;

        if(v[meio]==x){
            ans = meio;
            break;
        }

        else if(v[meio]>x){
            ans = min(ans,meio);
            fim = meio - 1;
        }

        else inicio = meio+1;
    }
    return ans;
}

int main(){

    cin>>n;

    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;

        if(i==1) v[i] = temp;
        else v[i] = v[i-1] + temp;
    }

    cin>>k;

    for(int i=1;i<=k;i++){
        int alvo;
        cin>>alvo;

        cout<<busca(alvo)<<endl;
    }






    return 0;
}