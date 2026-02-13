#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

map<int, int> mask;
map<pair<int,int>, int> nimber;

int get_grundy(int x, int m){
    if(nimber[{x,m}]) return nimber[{x,m}];
    if(m == ((1LL<<(x+1))-1) )return 0;

    set<int> estado;
    for(int i=1; i<=x; i++){
        if(m & (1<<(i-1))) continue;
        int new_m = m|(1<<(i-1));
        estado.insert(get_grundy(x-i, new_m));
    }
    int mex = 0;
    while(estado.find(mex)!=estado.end()) mex++;
    return nimber[{x,m}] = mex;
}

int32_t main()
{_

    int n; cin>>n;
    int ans = 0;

    for(int i=1; i<=n; i++){
        int x; cin>>x;
        ans^= get_grundy(x,0);
    }

    if(ans) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
}
