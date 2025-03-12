#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 +10)
int n, m;
int a[MAX], b[MAX];

int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int p1 = 1, p2 = 1;

    while(p1<=n || p2<=m){
        if(a[p1]<b[p2]){
            cout<<a[p1]<<" ";
            p1++;
        }

        else{
            cout<<b[p2]<<" ";
            p2++;
        }

        if(p1>n){
            for(int i=p2;i<=m;i++) cout<<b[i]<<" ";
            p2 = m+1;
        }

        else if(p2>m){
            for(int i=p1;i<=n;i++) cout<<a[i]<<" ";
            p1 = n+1;
        }
    }

    cout<<endl;

    return 0;
}