#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5+10)

int n, t, q, v[MAX], dif[MAX];

int main(){

    cin>>t;

    while(t--){
        cin>>n;

        for(int i=1; i<=n; i++) cin>>v[i];

        for(int i=1;i<=n;i++){
            dif[i] = i-1;

            while(v[i] == v[dif[i]]) dif[i] = dif[dif[i]];
        }
        cin>>q;

        while(q--){
            int l, r;
            cin>>l>>r;

            if(dif[r]<l){
                cout<<"-1 -1"<<endl;
            }
            
            else{
                cout<<dif[r]<<" "<<r<<endl;
            }
        }   
    }
    cout<<endl;

    return 0;
}