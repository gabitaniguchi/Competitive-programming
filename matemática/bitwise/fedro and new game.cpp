#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans=0;

int main(){

    cin>>n>>m>>k;
    int num[m+5];
    deque<int> fedor;

    for(int i=1; i<=m+1; i++){
        cin>>num[i];
    }

    for(int i=0; i<=n; i++){
        if((num[m+1]>>i) & 1) fedor.push_front(1);
        else fedor.push_front(0); 
    }

    for(int i=1; i<=m; i++){
        int amg = 0;
        for(int j=0; j<=n; j++){
            int x;
            if((num[i]>>j)&1) x=1; 
            else x=0;
            
            if(x!=fedor[n-j]) amg++;
            
        }
        
        if(amg<=k) ans++;
        
    }

    cout<<ans<<endl;

    return 0;
}