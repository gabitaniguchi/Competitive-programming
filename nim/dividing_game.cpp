#include <bits/stdc++.h>
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define MAXN (int)(1e5+10)
int prime[MAXN], nimber[MAXN], vis[MAXN];

void erastotenes(){

    for(int i=2; i<MAXN;i++) prime[i] = 1;
    for(int i=2; i*i<MAXN; i++){
        if(prime[i]){
            for(int j=i*i; j<MAXN; j+=i) prime[j] = 0;
        }
    }
}

void precomp(){
    nimber[1] = 0;
    for(int i=2; i<MAXN; i++){
        if(prime[i]) nimber[i] = 1;
        else{
            for(int j=1;j*j<=i; j++){
                if(i%j==0){
                    vis[nimber[j]] = i;
                    if(j!=1) vis[nimber[i/j]] = i;
                }
            }
            int mex = 0;
            while(vis[mex]==i) mex++;
            nimber[i] = mex;
        }
    }
}

int32_t main()
{_

    erastotenes();
    precomp();

    int n, ans=0;
    cin>>n;

    for(int i=1; i<=n; i++){
        int x; cin>>x;
        ans^= nimber[x];
    }

    if(ans) cout<<"Anna"<<endl;
    else cout<<"Bruno"<<endl;
    
}