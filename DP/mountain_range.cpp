#include <bits/stdc++.h>
 
using namespace std;
#define MAXN (int)(2e5+10)
#define int long long
int pdir[MAXN], pesq[MAXN], dp[MAXN];
int seg[4*MAXN];

void update(int node, int l, int r, int index, int x){
    if(l==r){
        seg[node]=x;
        return;
    }

    int mid = (l+r)/2;

    if(l<=index && mid>=index) update(2*node, l, mid, index, x);
    else update(2*node+1, mid+1, r, index, x);

    seg[node] = max(seg[2*node], seg[2*node+1]);
}

int query(int node, int tl, int tr, int l, int r){
    if(l>tr || r<tl) return 0;
    if(l<=tl && r>=tr) return seg[node];

    int mid = (tl+tr)/2;

    return max(query(2*node, tl, mid, l, r), query(2*node+1, mid+1, tr, l, r));
}
 
int32_t main(){
    int n; cin>>n;
    pair<int,int> v[n+5];
    
    for(int i=1; i<=n; i++) {
        int x;cin>>x;
        v[i] = {x,i};
    }
    
    pdir[n] = n+1;
    
    for(int i=n-1; i>=1; i--){
        pdir[i] = i+1;
        while(pdir[i]<=n && v[i].first>v[pdir[i]].first) pdir[i] = pdir[pdir[i]];
    }
 
    pesq[1] = 0;
    for(int i=2; i<=n;i++){
        pesq[i] = i-1;
        while(pesq[i]>=1 && v[i].first>v[pesq[i]].first) pesq[i] = pesq[pesq[i]];
    }
 
    sort(v+1, v+1+n);
 
    int ans = 1;
 
    for(int i=1; i<=n;i++){
        int pos = v[i].second;
        int l = pesq[pos]+1;
        int r = pdir[pos]-1; 
        dp[pos] = 1 + query(1,1,n,l,r);
        update(1,1,n,pos,dp[pos]);
        ans = max(ans, dp[pos]);
    }
 
    cout<<ans<<endl;
}