#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)

int seg[4*MAXN], v[MAXN], n;

void build(int node, int l, int r){
    if(l==r){
        seg[node] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = seg[2*node]+seg[2*node+1];
}

void update(int node, int l, int r, int idx){
    if(l==r){
        seg[node] = 0;
        return;
    }

    int mid = (l+r)/2;
    if(l<=idx && idx<=mid) update(2*node, l, mid, idx);
    else update(2*node+1, mid+1,r, idx);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int node, int l, int r, int idx){
    if(l==r && seg[node]==idx) {
        update(1,1,n,r);
        return v[r];
    }

    int mid = (l+r)/2;
    if(seg[2*node]>=idx) return query(2*node, l, mid, idx); 
    else return query(2*node+1, mid+1, r, idx-seg[2*node]);
}

int32_t main()
{_
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    build(1,1,n);

    for(int i=1;i<=n;i++){
        int idx; cin>>idx;
        cout<<query(1,1,n,idx)<<" ";
    }
    cout<<endl;
}