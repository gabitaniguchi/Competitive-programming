#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)
#define INF (int)(1e9)

int seg[4*MAXN];
int in[MAXN], out[MAXN], vis[MAXN], t=1;
vector<int> g[MAXN];
map<pair<int,int>,int> ord;
vector<pair<pair<int,int>,int>> v;
int n, q;

void dfs(int x){
    vis[x]=1;
    in[x]=t;
    
    for(auto nxt: g[x]){
        if(vis[nxt]) continue;
        t++;
        dfs(nxt);
    }

    t++;
    out[x]=t;
}

void build(int node, int l, int r){
    if(l==r){
        seg[node] = v[l-1].second;
        return;
    }

    int mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    seg[node] = seg[2*node] + seg[2*node+1];
}

void update(int node, int l, int r, int idx, int x){
    if(l==r){
        seg[node] = x;
        return;
    }

    int mid = (l+r)/2;
    if(l<=idx && idx<=mid) update(2*node, l, mid, idx, x);
    else update(2*node+1, mid+1, r, idx, x);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int node, int tl, int tr, int l, int r){
    if(l<=tl && tr<=r) return seg[node];
    if(tl>r || tr<l) return 0;

    int mid = (tl+tr)/2;
    return query(2*node, tl, mid, l, r) +
        query(2*node+1, mid+1,tr, l, r);
}

int busca(int xout){
    int i=0, f=n-1;
    int r=0;

    i=0, f=n-1;
    while(i<=f){
        int mid = (i+f)/2;
        if(v[mid].first.first<xout){
            r=max(mid,r);
            i=mid+1;
        }
        else f=mid-1;
    }

    return r+1;
}

int32_t main()
{_
    cin>>n>>q;
    int custo[n+5];
    for(int i=1;i<=n;i++) cin>>custo[i];

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    for(int i=1;i<=n;i++){
        v.push_back({{in[i], out[i]}, custo[i]});
    }
    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        ord[{v[i].first.first, v[i].first.second}] = i+1;
    }

    build(1,1, n);

    // for(int i=1;i<=9;i++){
    //     cout<<"seg "<<i<<" : "<<seg[i]<<endl;
    // }

    while(q--){
        int t, s, x;
        cin>>t>>s;
        if(t==2){
            auto r = busca(out[s]);
            //cout<<"l "<<l<<" r "<<r<<endl;
            cout<<query(1,1,n,ord[{in[s],out[s]}],r)<<endl;
        } 
        else{
            cin>>x;
            update(1,1,n,ord[{in[s],out[s]}],x);
        }
    }

    
}