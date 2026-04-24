#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(6e5+10)

int seg[4*MAXN];
vector<int> coord, v;
vector<pair<char,pair<int,int>>> queries;

void update(int node, int l, int r, int idx, int x){
    if(l==r){
        seg[node] += x;
        return;
    }

    int mid = (l+r)/2;
    if(l<=idx && idx<=mid) update(2*node,l, mid, idx, x);
    else update(2*node+1, mid+1, r, idx, x);
    seg[node] = seg[2*node]+seg[2*node+1];
}

int query(int node, int tl, int tr, int l, int r){
    if(l<=tl && tr<=r) return seg[node];
    if(tr<l || tl>r) return 0;
    int mid = (tl+tr)/2;
    return query(2*node,tl,mid,l,r) + query(2*node+1, mid+1, tr, l,r);
}
int get_coord(int x){
    return lower_bound(coord.begin(), coord.end(), x) - coord.begin() + 1;
}

int32_t main()
{_
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        coord.push_back(x);
        v.push_back(x);
    }

    for(int i=1;i<=q;i++){
        char c;
        int a,b;
        cin>>c>>a>>b;
        queries.push_back({c,{a,b}});
        if(c=='?') coord.push_back(a);
        coord.push_back(b);
    }

    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    int tam = coord.size();

    for(int i=0;i<n;i++){
        int x = get_coord(v[i]);
        update(1,1,tam,x,1);
        v[i]=x;
    }

    for(int i=0;i<q;i++){
        auto [op, t] = queries[i];
        auto [a,b] = t;
        if(op=='?') {
            a = get_coord(a);
            b = get_coord(b);

            cout<<query(1,1,tam,a,b)<<endl;
        }
        else {
            b = get_coord(b);

            update(1,1,tam,b,1);
            update(1,1,tam, v[a-1], -1);
            v[a-1] = b;
        }

    }
    
    
}