#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10)

int n, m;
int a[MAX], b[MAX];

int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int p1 = 1, p2 = 1;
    int ANS = 0;

    while(p2<=m){
        int ans = 0;

        while(a[p1]<=b[p2] && p1<=n){
            if(a[p1]==b[p2]) ans ++;
            p1++;
        }

        while(b[p2] == b[p2+1]){
            p2++;
            ANS += ans;
        }

        p2++;

        ANS += ans;
    }

    cout<<ANS<<endl;

    return 0;
}