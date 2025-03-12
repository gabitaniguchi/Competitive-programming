#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)
#define ll long long

int n, q;
ll v[MAX], seg[4*MAX];

void build(int node, int l, int r){
    if(l==r){
        seg[node] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    seg[node] = seg[2*node] + seg[2*node + 1];
}

void update (int node, int l, int r, int index, int x){
    if(l==r){
        seg[node] = x;
        v[index] = x;
        return;
    }

    int mid = (l+r)/2;

    if(l<=index && index<=mid) update(2*node, l, mid, index, x);
    else update(2*node+1, mid+1, r, index, x);

    seg[node] = seg[2*node] + seg[2*node+1];
}

ll query(int node, int tl, int tr, int l, int r){
    if(r<tl || l>tr) return 0;
    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;

    return query(2*node, tl, mid, l, r) + query(2*node+1, mid+1, tr, l, r);
}

int main(){

    cin>>n>>q;

    for(int i=0;i<n;i++) cin>>v[i];

    build(1,0,n-1);

    while(q--){
        int t, a, b;
        cin>>t>>a>>b;

        if(t==1) update(1, 0, n-1, a, b);
        else cout<<query(1, 0, n-1, a, b-1)<<endl;
    }

    return 0;
}