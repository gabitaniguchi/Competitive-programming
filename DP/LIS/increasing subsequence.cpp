// LIS com seg e usando compressão de coordenadas
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX (int)(200010)

map<int, int> comprime;
int n, dp[MAX], a[MAX], t[MAX], ordenado[MAX], seg[4*MAX], ans=0;

void build(int node, int l, int r){
    if(l==r){
        seg[node] = t[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
}

void update(int node, int l, int r, int index, int x){
    if(l==r){
        seg[node] = x;
        return;
    }

    int mid = (l+r)/2;

    if(l<=index && index<=mid) update(2*node, l, mid, index, x);
    else update(2*node+1, mid+1, r, index, x);

    seg[node] = max(seg[2*node], seg[2*node+1]);

    return;
}

int query (int node, int tl, int tr, int l, int r){
    if(r<tl || l>tr) return 0;
    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;
    return max(query(2*node, tl, mid, l, r), query(2*node+1, mid+1, tr, l, r));
}

int32_t main(){

    cin>>n;

    
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        ordenado[i] = a[i];
    }
    
    sort(ordenado+1, ordenado+n+1);
    
    int menor = 0;
    
    for(int i=1; i<=n; i++){
        if(comprime.find(ordenado[i]) == comprime.end()) comprime[ordenado[i]] = ++menor;
    }
    build(1, 1, menor);

    for(int i=1; i<=n; i++){
        dp[i] = query(1, 1, menor, 1, comprime[a[i]]-1) + 1;
        update(1, 1, menor, comprime[a[i]], dp[i]);
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}