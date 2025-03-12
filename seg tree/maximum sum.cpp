#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5+10)
#define ll long long 

typedef struct no{

    ll ans;
    ll sum;
    ll pref;
    ll suf;

} no;

int n, q;
ll v[MAX];
no seg[4*MAX];

void build (int node, int l, int r){
    if(l==r){
        seg[node].sum = v[l];
        seg[node].ans = v[l];
        seg[node].pref = v[l];
        seg[node].suf = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    seg[node].sum = seg[2*node].sum + seg[2*node+1].sum;
    seg[node].ans = max({seg[2*node].ans, seg[2*node+1].ans, seg[2*node].suf+ seg[2*node+1].pref});
    seg[node].pref = max({seg[2*node].pref, seg[2*node].sum + seg[2*node+1].pref});
    seg[node].suf = max({seg[2*node+1].suf, seg[2*node+1].sum + seg[2*node].suf});

}

void update (int node, int l, int r, int index, int x){
    if(l==r){
        seg[node].sum = x;
        seg[node].ans = x;
        seg[node].pref = x;
        seg[node].suf = x;
        v[index] = x;
        return;
    }

    int mid = (l+r)/2;

    if(l<=index && index<=mid) update(2*node, l, mid, index, x);
    else update(2*node+1, mid+1, r, index, x);

    seg[node].sum = seg[2*node].sum + seg[2*node+1].sum;
    seg[node].ans = max({seg[2*node].ans, seg[2*node+1].ans, seg[2*node].suf+ seg[2*node+1].pref});
    seg[node].pref = max({seg[2*node].pref, seg[2*node].sum + seg[2*node+1].pref});
    seg[node].suf = max({seg[2*node+1].suf, seg[2*node+1].sum + seg[2*node].suf});
}

int main(){

    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>v[i];

    build(1, 1, n);

    while(q--){
        int i, x;
        cin>>i>>x;

        update(1, 1, n, i, x);
        if(seg[1].ans<0) cout<<0<<endl;
        else cout<<seg[1].ans<<endl;
    }

    return 0;
}