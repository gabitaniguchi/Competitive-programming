#include<bits/stdc++.h>

using namespace std;
#define MAX (int)(2e6+10)

int n, target;
int sand[MAX], pref[MAX];

int main(){

    cin>>n>>target;

    for(int i=1;i<=n; i++){
        cin>>sand[i];

        sand[n+i] = sand[i];
    }

    for(int i=1;i<=2*n; i++) pref[i] = pref[i-1] + sand[i];

    if(target>pref[n]) {
        cout<<"0"<<endl;
        return 0;
    }

    int fim = 1, ans = 0;

    for(int inicio=1; inicio<=n; inicio++){

        while(fim<=2*n && pref[fim+1]-pref[inicio] <= target){
            fim++;

            if(pref[fim] - pref[inicio] == target) ans++;
        }

    }

    cout<<ans<<endl;    

    return 0;
}