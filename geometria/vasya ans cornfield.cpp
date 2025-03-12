#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,d,m;
    cin>>n>>d>>m;

    while(m--){
        int x, y;
        cin>>x>>y;

        if(d<=(y+x) && (y+x)<=(2*n-d) && (x-y)>=(-d) && (x-y)<=d){
            printf("YES\n");
        }

        else printf("NO\n");
    }


    return 0;
}