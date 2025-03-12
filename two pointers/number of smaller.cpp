#include<bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int n, m;
int a[MAX], b[MAX];

int main(){

    cin>>n>>m;
    int ans = 0;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int p1 = 1, p2 = 1;

    while(p2<=m){
        while(a[p1]<b[p2] && p1<=n) {
            p1++;
            ans++;
        }

        cout<<ans<<" ";
        p2++;
    }


    return 0;
}