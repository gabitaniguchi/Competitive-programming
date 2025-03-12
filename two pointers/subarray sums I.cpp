#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define MAX (int) (2e5 + 10)

ll v[MAX];

int main(){

    int n;
    ll target;

    cin>>n>>target;

    for(int i=1;i<=n;i++) cin>>v[i];

    ll l = 1, temp=0, ans=0;

    for(ll r=1; r<=n; r++){

        temp += v[r];

        if(temp==target) ans++;

        while(temp>=target){
            temp -= v[l];
            if(temp==target) ans++;
            l++;
        }

    }

    cout<<ans<<endl;

    return 0;
}