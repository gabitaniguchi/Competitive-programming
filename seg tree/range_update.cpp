#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)

int v[MAXN], seg[4*MAXN], lazy[4*MAXN], n, q;

void unlazy(int node, int tl, int tr){
    if(lazy[node]==0) return;

    seg[node] += lazy[node];
    if(tl!=tr){
        lazy[2*node+1] += lazy[node];
        lazy[2*node] += lazy[node];
    }
    lazy[node]=0;
}

void build(int node, int l, int r){
    if(l==r){
        seg[node] = v[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
}

void update(int node,int tl, int tr, int l, int r, int x){
    unlazy(node, tl, tr);

    if(l<=tl && tr<=r) {
        lazy[node] += x;
        unlazy(node, tl, tr);
        return;
    }
    if(tl>r || tr<l) return;

    int mid = (tl+tr)/2;
    update(2*node, tl,mid,l, r, x);
    update(2*node+1, mid+1, tr, l, r,x); 
}

int query(int node, int tl, int tr, int idx){
    unlazy(node, tl, tr);
    if(tl==tr && tr==idx) return seg[node];

    int mid=(tl+tr)/2;
    if(tl<=idx && idx<=mid) return query(2*node, tl, mid, idx);
    else return query(2*node+1, mid+1, tr,idx);
}

int32_t main()
{_
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>v[i];

    build(1,1,n);

    while(q--){
        int t,l,r, x;
        cin>>t;
        if(t==1) cin>>l>>r>>x;
        else cin>>x;

        if(t==1) update(1,1,n,l,r,x);
        else cout<<query(1,1,n,x)<<endl;
    }
}