#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define INF (int)(1e18+10)

int seg[4*MAXN], v[MAXN];
int n,q;

void build(int node, int l, int r){
    if(l==r) {
        seg[node] = v[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = (seg[2*node]^seg[2*node+1]);
}

void update(int node, int l, int r, int idx, int x){
    if(l==r){
        seg[node] = x;
        return;
    }

    int mid = (l+r)/2;
    if(l<=idx && idx<=mid) update(2*node, l, mid, idx, x);
    else update(2*node+1, mid+1, r, idx, x);

    seg[node] = (seg[2*node]^seg[2*node+1]);
}

int query(int node, int tl, int tr, int l, int r){
    if(l<=tl && tr<=r) return seg[node];
    if(l>tr || r<tl) return 0;

    int mid = (tl+tr)/2;
    return (query(2*node, tl, mid, l, r)^query(2*node+1, mid+1, tr, l, r));
}

int32_t main()
{_
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>v[i];
    build(1, 1, n);
    while(q--){
        int l, r;
        cin>>l>>r;

        cout<<query(1,1,n,l,r)<<endl;
    }
}