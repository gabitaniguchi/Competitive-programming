#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e9+10)

int vis[5];
map<int,int> nimber;

void k_par(){
    nimber[1] = 1;
    nimber[2] = 2;
}

void k_impar(){
    nimber[1] = 1;
    nimber[2] = 0;

    for(int i=3; i<MAXN-2; i++){
        cout<<i<<endl;
        if(i%2==1){
            if(nimber[i-1]==0) nimber[i] = 1;
            else nimber[i] = 0;
        }
        else{
            vis[nimber[i-1]] = i;
            vis[nimber[i/2]] = i;

            int mex=0;
            while(vis[mex]==i) mex++;
            nimber[i] = mex;
        }
    }
}

int32_t main()
{_

    int n, k, ans=0;
    cin>>n>>k;

    if(k%2==0) k_par();
    else k_impar();

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(k%2==0 && x>2) ans^= x%2==0? 1: 0;
        else ans^=nimber[x];
    }

    if(ans!=0) cout<<"Kevin"<<endl;
    else cout<<"Nicky"<<endl;
}