#include <bits/stdc++.h>

using namespace std;

#define MAX 200010
int n,m;
int a[MAX];

int busca (int x){
    int inicio = 1;
    int fim = n;
    int ans = 0;

    while(fim>=inicio){
        int meio = (fim+inicio)/2;

        if(a[meio]<=x){
            ans = max(ans,meio);
            inicio = meio+1;
        }

        else fim = meio-1;
    }

    return ans;
}

int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1, a+n+1);

    //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    for(int i=1;i<=m;i++){
        int target;
        cin>>target;

        cout<<busca(target);
        //cout<<" "<<a[busca(target)]<<endl;

        if(i<m) cout<<" ";
        else cout<<endl;
    }

    return 0;
}