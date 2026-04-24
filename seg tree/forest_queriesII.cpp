#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e3+10)

int seg[4*MAXN][4*MAXN];
int m[MAXN][MAXN], n, q;

void build_x(int node_y, int ly, int ry, int node_x, int lx, int rx){
    if (lx == rx) {
        if (ly == ry) {
            // folha em Y e folha em X (um único elemento da matriz)
            seg[node_y][node_x] = m[ly][lx];
        } else {
            // Nó interno em Y, mas folha em X: combina os valores dos filhos de Y
            seg[node_y][node_x] = seg[2 * node_y][node_x] + seg[2 * node_y + 1][node_x];
        }
        return;
    }
    
    int mid = (lx + rx) / 2;
    build_x(node_y, ly, ry, 2 * node_x, lx, mid);
    build_x(node_y, ly, ry, 2 * node_x + 1, mid + 1, rx);
    
    // O valor do nó atual em X é a soma de seus filhos em X
    seg[node_y][node_x] = seg[node_y][2 * node_x] + seg[node_y][2 * node_x + 1];
}

void build_y(int node, int ly, int ry){
    if(ly!=ry){
        int mid=(ly+ry)/2;
        build_y(2*node,ly,mid);
        build_y(2*node+1,mid+1, ry);
    }

    build_x(node, ly, ry, 1, 1, n);
}

void update_x(int node_y, int ly, int ry, int node_x, int lx, int rx, int x, int y, int value) {
    if (lx == rx) {
        if (ly == ry){
            seg[node_y][node_x] = value;
            m[y][x] = value;
        }
        else
            seg[node_y][node_x] = seg[2*node_y][node_x] + seg[2*node_y+1][node_x];
    } 
    else {
        int mid = (lx + rx) / 2;
        if (x <= mid)
            update_x(node_y, ly, ry, 2*node_x, lx, mid, x, y, value);
        else
            update_x(node_y, ly, ry, 2*node_x+1, mid+1, rx, x, y, value);
        seg[node_y][node_x] = seg[node_y][2*node_x] + seg[node_y][2*node_x+1];
    }
}

void update_y(int node_y, int ly, int ry, int x, int y, int value){
    if(ly!=ry){
        int mid = (ly+ry)/2;
        if(y<=mid) update_y(2*node_y, ly, mid, x, y, value);
        else update_y(2*node_y+1, mid+1, ry, x, y, value);
    }
    update_x(node_y, ly, ry, 1, 1, n, x, y, value);

}

int query_x(int node_y, int node_x, int lx, int rx, int x1, int x2){
    // fora do intervalo
    if(x1>rx || x2<lx) return 0;
    if(x1<=lx && rx<=x2) return seg[node_y][node_x];

    int mid = (lx+rx)/2;
    return query_x(node_y, 2*node_x, lx, mid, x1,x2) + query_x(node_y, 2*node_x+1, mid+1, rx, x1,x2);
}

int query_y(int node_y, int ly, int ry, int y1, int y2, int x1, int x2){
    if(y1>ry || y2<ly) return 0;
    if(y1<=ly && ry<=y2) {
        return query_x(node_y, 1, 1, n, x1, x2);
    }

    int mid = (ly+ry)/2;
    return query_y(2*node_y, ly, mid, y1,y2,x1,x2) + query_y(2*node_y+1, mid+1, ry, y1,y2,x1,x2);
}

int32_t main()
{_
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            if(c=='*') m[i][j]=1;
        }
    }

    build_y(1,1,n);

    while(q--){
        int t,y1,x1,y2,x2;
        cin>>t>>y1>>x1;
        if(t==2) {
            cin>>y2>>x2;
            cout<<query_y(1,1,n,y1,y2,x1,x2)<<endl;
        }
        else{
            int val = m[y1][x1]==1? 0: 1;
            update_y(1,1,n,x1,y1, val);
        }
    }
    
}