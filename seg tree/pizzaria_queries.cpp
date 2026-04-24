#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define INF (int)(1e18)

int segMenor[4*MAXN], segMaior[4*MAXN], v[MAXN];

void build_Menor(int node, int l, int r){
    if(l==r){
        segMenor[node] = v[l] - l;
        return;
    }
    int mid=(l+r)/2;
    build_Menor(2*node,l,mid);
    build_Menor(2*node+1, mid+1, r);
    segMenor[node] = min(segMenor[2*node], segMenor[2*node+1]);
}

void build_Maior(int node, int l, int r){
    if(l==r){
        segMaior[node] = v[l] + l;
        return;
    }
    int mid=(l+r)/2;
    build_Maior(2*node,l,mid);
    build_Maior(2*node+1, mid+1, r);
    segMaior[node] = min(segMaior[2*node], segMaior[2*node+1]);
}

void update_Menor(int node, int l, int r, int idx, int x){
    if(l==r){
        segMenor[node] = x - idx;
        return;
    }
    int mid = (l+r)/2;
    if(l<=idx && idx<=mid) update_Menor(2*node, l, mid, idx, x);
    else update_Menor(2*node+1, mid+1, r, idx, x);
    segMenor[node] = min(segMenor[2*node], segMenor[2*node+1]);
}

void update_Maior(int node, int l, int r, int idx, int x){
    if(l==r){
        segMaior[node] = x + idx;
        return;
    }
    int mid = (l+r)/2;
    if(l<=idx && idx<=mid) update_Maior(2*node, l, mid, idx, x);
    else update_Maior(2*node+1, mid+1, r, idx, x);
    segMaior[node] = min(segMaior[2*node], segMaior[2*node+1]);
}

int query_Menor(int node, int tl, int tr, int l, int r){
    if(l<=tl && tr<=r) return segMenor[node];
    if(tl>r || tr<l) return INF;

    int mid = (tl+tr)/2;
    return min(query_Menor(2*node, tl, mid, l, r), query_Menor(2*node+1, mid+1, tr, l, r));
}

int query_Maior(int node, int tl, int tr, int l, int r){
    if(l<=tl && tr<=r) return segMaior[node];
    if(tl>r || tr<l) return INF;

    int mid = (tl+tr)/2;
    return min(query_Maior(2*node, tl, mid, l, r), query_Maior(2*node+1, mid+1, tr, l, r));
}

int32_t main()
{_
    int n, q; cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>v[i];
    build_Menor(1,1,n);
    build_Maior(1,1,n);
    while(q--){
        int t, k,x;
        cin>>t>>k;
        if(t==1) {
            cin>>x;
            update_Maior(1,1,n,k,x);
            update_Menor(1,1,n,k,x);
        }
        else{
            int menor = query_Menor(1,1,n,1,k);
            int maior = query_Maior(1,1,n,k,n);
            int ans = min(menor+k, maior-k);
            cout<<ans<<endl;
        }
    }
}