#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e6)

int v[MAX], seg[MAX], dist[MAX];

void build (int node, int l, int r){
    if(l==r){
        seg[node] = v[l];
        dist[node] = 0;
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build (2*node+1, mid+1, r);

    dist[node] = dist[2*node+1] + 1;

    if(dist[node]%2==0) seg[node] = seg[2*node] ^ seg[2*node+1];
    else seg[node] = seg[2*node] | seg[2*node+1];
}

void update (int node, int l, int r, int idx, int x){
    if(l==r) {
        seg[node] = x;
        v[l] = x;
        return;
    }

    int mid = (l+r)/2;


    if(l<=idx && idx<=mid) update(2*node, l, mid, idx, x);
    else update(2*node+1, mid+1, r, idx, x);

    if(dist[node]%2==0) seg[node] = seg[2*node] ^ seg[2*node+1];
    else seg[node] = seg[2*node] | seg[2*node+1];
}

int query (int node, int tr, int tl, int l, int r){
    if(r<tl || l>tr) return 0;

    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;

    if(dist[node]%2==0) return query(2*node, tl, mid, l, r) ^ query(2*node+1, mid+1, tr, l, r);
    else return query(2*node, tl, mid, l, r) | query(2*node+1, mid+1, tr, l, r);
} 

int main(){

    int n, m;
    cin>>n>>m;
    int tam = pow(2,n);

    for(int i=1;i<=tam;i++) cin>>v[i];

    build(1,1,tam);
    
    while(m--){
        int a,b;
        cin>>a>>b;

        update(1,1, tam, a, b);
        cout<<query(1,1,tam,1,tam)<<endl;
    }

    return 0;
}