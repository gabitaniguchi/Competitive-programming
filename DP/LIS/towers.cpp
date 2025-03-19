#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX (int)(2e5+10)

int seg[4*MAX], v[MAX], temp[MAX], dp[MAX], n, ans=0;
map<int,int> mapa;
   
void build(int node, int l, int r){
    if(l==r) {
        seg[node] = 0;
        return;
    }
    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node + 1, mid+1, r);
}

void update(int node, int l, int r, int index, int x){
    if(l==r) {
        seg[node] = x;
        return;
    }

    int mid = (l+r)/2;

    if(l<=index && index<=mid) update(2*node, l, mid, index, x);
    else update(2*node+1, mid+1, r, index, x);

    seg[node] = max(seg[2*node], seg[2*node+1]);
    return;
}

int query(int node, int tl, int tr, int l, int r){
    if(r<tl || l>tr) return 0;
    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;
    return max(query(2*node, tl, mid, l, r), query(2*node+1, mid+1, tr, l, r));
}

int comprime_coordenadas(){
    
    for(int i=1; i<=n; i++){
        cin>>v[i];
        temp[i] = v[i];
    }

    sort(temp+1, temp+n+1);

    int menor = 0;
    
    for(int i=1; i<=n; i++){
        if(mapa.find(temp[i])==mapa.end()) 
            mapa[temp[i]] = ++menor;
    }

    return menor;
}

int32_t main(){

    cin>>n;
    int menor = comprime_coordenadas();
    build(1,1,n);
    for(int i=1; i<=n; i++){
        dp[i] = query(1, 1, menor, mapa[v[i]]+1, menor) + 1;
        if(dp[i]==1) ans++;
        update(1,1,menor,mapa[v[i]], dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}