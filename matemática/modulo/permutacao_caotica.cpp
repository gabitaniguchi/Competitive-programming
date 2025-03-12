#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MOD (int)(1e9+7)
#define MAX (int)(1e5+10)

ll perm_caotica[MAX];

void caotica(int N){
    perm_caotica[0] = 1;
    perm_caotica[1] = 0;
    perm_caotica[2] = 1;
    for(int i=3;i<=N;i++){
        ll s = (perm_caotica[i-1] + perm_caotica[i-2])%MOD;
        perm_caotica[i] = (i-1) * s % MOD;
    }
}

int main(){




    return 0;
}