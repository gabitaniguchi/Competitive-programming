#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)

int n, q, v[MAX], seg[4*MAX];

void build(int node, int l, int r){
    if(l==r){
        seg[node] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node,l,mid);
    build(2*node+1, mid+1, r);

    seg[node] = seg[2*node] + seg[2*node+1];
}

void update(int node, int l, int r, int index, int x){
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

int query (int node, int l, int r,int target){

    if(l==r) return l;

    int mid = (l+r)/2;

    if((seg[2*node])>= target) return query(2*node, l, mid, target);
    else return query(2*node+1, mid+1, r, target- seg[2*node]);
}

int main(){

    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>v[i];

    build(1,1,n);

    while(q--){
        int t, i;
        cin>>t>>i;
        i++;

        if(t==1){
            if(v[i]==0) update(1, 1, n, i, 1);
            else update(1, 1, n, i, 0);
        }

        else cout<<query(1, 1, n, i)-1<<endl;
    }





    return 0;
}