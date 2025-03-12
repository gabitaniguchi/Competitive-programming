#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    int ultimo, resposta=0;

    for(int i=1; i<=n; i++){
 
        int vi;
        cin >> vi;

        if(i == 1){
            ultimo = vi;
            resposta++;
        }

        else if(ultimo != vi){
            ultimo = vi;
            resposta++;
        }
    }

    cout << resposta << "\n";

    return 0;
}