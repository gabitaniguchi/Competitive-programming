#include <bits/stdc++.h>

using namespace std;

#define x first 
#define y second
#define ll long long int

ll dot (pair<ll,ll> a, pair<ll,ll> b){
    return a.x*b.y - a.y*b.x;
}

pair<ll,ll> subt (pair<ll, ll> a, pair<ll,ll> b){
    return {a.x-b.x, a.y-b.y};
}

int main(){

    int n;

    scanf("%d", &n);

    pair<ll,ll> P[n+5];

    for(int i=0; i<n; i++){
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        P[i] = {xi,yi};
    }

    ll area = 0;

    for(int i=1; i<n-1; i++){
        area += dot(subt(P[i], P[0]), subt(P[i+1], P[0]));
    }

    cout<<abs(area)<<endl;

    return 0;
}