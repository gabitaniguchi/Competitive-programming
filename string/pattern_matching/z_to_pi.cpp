#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e6+10)
int pi[MAXN], z[MAXN];

void z_to_pi(int n) {
    for (int i = 1; i < n; i++) {
        if (z[i] > 0) {
            // O sufixo que termina em i + z[i] - 1 tem tamanho z[i]
            pi[i + z[i] - 1] = max(pi[i + z[i] - 1], z[i]);
        }
    }
    
    // Propagação: se pi[i] = k, então pi[i-1] é pelo menos k-1
    for (int i = n - 1; i > 0; i--) {
        pi[i - 1] = max(pi[i - 1], pi[i] - 1);
    }
}

int32_t main()
{_
    int n; cin>>n;
    
    for(int i=0; i<n;i++){
        cin>>z[i];
    }
    
    z_to_pi(n);
    
    for(int i=0; i<n;i++) cout<<pi[i]<<" ";
    cout<<endl;
}