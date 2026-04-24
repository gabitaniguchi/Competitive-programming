#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e6+10)
int pi[MAXN], z[MAXN];

void pi_to_z(int n){
    for(int i=1;i<n;i++){
        if(pi[i]>0) z[i-pi[i]+1] = max(z[i-pi[i]+1], pi[i]);
    }

    int i=1;
    while(i<n){
        if(z[i]>0) {
            int j=1;
            while(j<z[i] && z[i+j]<z[i]-j){
                z[i+j]=max(z[i+j], min(z[j], z[i]-j));
                j+=1;
            }
            i+=j;
        }
        else i+=1;
    }
}

int32_t main()
{_
    int n; cin>>n;
    
    for(int i=0; i<n;i++){
        cin>>pi[i];
    }
    
    pi_to_z(n);
    
    for(int i=0; i<n;i++) cout<<z[i]<<" ";
    cout<<endl;
}