#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define MOD (int)(1e9+7)

int seg[4*MAXN];

void update (int node, int l, int r, int index, int x){
    if(l==r){
        seg[node] += x;
        return;
    }

    int mid = (l+r)/2;

    if(l<=index && index<=mid) update(2*node, l, mid, index, x);
    else update(2*node+1, mid+1, r, index, x);

    seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int node, int tl, int tr, int l, int r){
    if(r<tl || l>tr) return 0;
    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;

    return query(2*node, tl, mid, l, r)%MOD + query(2*node+1, mid+1, tr, l, r)%MOD;
}

int32_t main()
{_
    int n;
    cin>>n;

    int v[n+5], ord[n+5], ans=0;
    map<int,int> comp;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        ord[i] = v[i];
    }

    sort(ord+1, ord+1+n);

    for(int i=1;i<=n;i++) {
        if(comp[ord[i]]==0) comp[ord[i]] = i;
    }
    for(int i=1;i<=n;i++){
        int temp = query(1,1,n,1,comp[v[i]]-1)%MOD+1;
        update(1,1,n,comp[v[i]], temp);
        ans += temp%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}