#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5+10)
#define ll long long 

typedef struct no{
    ll sum;
    ll pref;
} no;

int n, q;
ll v[MAX];
no seg[4*MAX];

void build (int node, int l, int r){
    if(l==r){
        seg[node].sum = v[l];
        seg[node].pref = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    seg[node].sum = seg[2*node].sum + seg[2*node+1].sum;
    seg[node].pref = max({seg[2*node].pref, seg[2*node].sum + seg[2*node+1].pref});
}

void update (int node, int l, int r, int index, int x){
    if(index < l || index > r) return;
    
    if(l==r){
        seg[node].sum = x;
        seg[node].pref = x;
        v[index] = x;
        return;
    }

    int mid = (l+r)/2;

    update(2*node, l, mid, index, x);
    update(2*node+1, mid+1, r, index, x);

    seg[node].sum = seg[2*node].sum + seg[2*node+1].sum;
    seg[node].pref = max({seg[2*node].pref, seg[2*node].sum + seg[2*node+1].pref});
   
}

no query (int node, int l, int r,int tl, int tr){

    if(l>tr || r<tl){
        no ans;
        ans.pref = ans.sum = 0;
        return ans;
    } 

    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;

    no left = query(2*node, l, r, tl, mid);
    no rigth = query(2*node+1, l, r, mid+1, tr);
    no ans;

    ans.sum = left.sum + rigth.sum;
    ans.pref = max(left.pref, left.sum + rigth.pref);
    return ans;
}

int main(){

    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>v[i];

    build(1, 1, n);

    while(q--){
        int o,i, x;
        cin>>o>>i>>x;

        if(o==1) update(1, 1, n, i, x);
        else{
            ll res = query(1, i, x, 1, n).pref;
            if(res<0) res = 0;
            cout<<res<<endl;
        }
    }

    return 0;
}