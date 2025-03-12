#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)
#define ll long long

int n,q;
ll v[MAX];
int const inf = 1e9 + 10;
pair<ll, ll> seg[4*MAX];

void build (int node, int l, int r){
    if(l==r) {
        seg[node] = {v[l],1};
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    if (seg[2*node].first == seg[2*node+1].first){
        seg[node] = {seg[2*node].first, seg[2*node].second+seg[2*node+1].second};
    }

    else{
        pair<ll,ll> val = min(seg[2*node],seg[2*node+1]);
        seg[node] = {val.first, val.second};
    }
}

void update(int node, int l, int r, int index, int x){
    if(l==r){
        seg[node].first = x;
        v[index] = x;
        return;
    }

    int mid = (l+r)/2;

    if(l<=index && mid>=index) update(2*node, l, mid, index, x);
    else update(2*node+1, mid+1, r, index, x);
   
    if (seg[2*node].first == seg[2*node+1].first){
        seg[node] = {seg[2*node].first, seg[2*node].second+seg[2*node+1].second};
    }

    else{
        pair<ll,ll> val = min(seg[2*node],seg[2*node+1]);
        seg[node] = {val.first, val.second};
    }
}

pair<ll,ll> query(int node, int tl, int tr, int l, int r){
    if(l>tr || r<tl) return {inf,0};
    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;

    pair<ll,ll> v1 = query(2*node, tl, mid, l, r);
    pair<ll,ll> v2 = query(2*node+1, mid+1, tr, l, r);

    if(v1.first==v2.first) return {v1.first, v1.second+v2.second};
    else{
        pair<ll,ll> val = min(v1,v2);
        return val;
    }
}

int main(){

    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>v[i];

    build(1,1,n);
    
    while(q--){
        int t, a, b;
        cin>>t>>a>>b;

        if(t==1) {
            update(1, 1, n, a+1, b);
        }
        else {
            pair<ll,ll> ans = query(1, 1, n, a+1, b);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }

}