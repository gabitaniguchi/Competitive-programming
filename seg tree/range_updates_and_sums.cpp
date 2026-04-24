#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(2e5+10)

struct Seg{
    int val;
    int lazy_sum;
    int lazy_set;
};

Seg seg[4*MAXN];
int v[MAXN];

void build(int node, int l, int r){
    if(l==r) {
        seg[node].val = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    seg[node].val = seg[2*node].val + seg[2*node+1].val;
}

void set(int node, int tl, int tr, int l, int r, int x){
    if(l<=tl && tr<=r) seg[node].val=x;
    
}

void update(int node, int l, int r, int op, int x){

}

int32_t main()
{_
    
}