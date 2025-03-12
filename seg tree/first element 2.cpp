#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)

int n, q, seg[4*MAX], v[MAX];

void build(int node, int l, int r){
    if(l==r) {
        seg[node] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    seg[node] = max(seg[2*node], seg[2*node+1]);
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

    seg[node] = max(seg[2*node], seg[2*node+1]);
}

int query(int node, int l, int r, int target, int lim){
    if(l==r) {
        if(l<lim || seg[node]<target) return -1;
        return l-1;
    }

    int mid = (l+r)/2;
    int ans;

    if(seg[2*node]>=target && mid>=lim) ans = query(2*node, l, mid, target, lim);
    else ans = -1;
    
    if(ans==-1) return query(2*node+1, mid+1, r, target, lim);
    else return ans;
}

int main(){

    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>v[i];

    build(1, 1, n);

    while(q--){
        int t, i, x;
        cin>>t>>i>>x;

        if(t==1) update(1, 1, n, i+1, x);
        
        else{
            if(seg[1]<i) cout<<-1<<endl;
            else cout<<query(1, 1, n, i, x+1)<<endl;
        }
    }



    return 0;
}