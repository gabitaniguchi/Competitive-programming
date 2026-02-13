#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)
int eh_primo[MAXN];
vector<int> primes;
void crivo(){
    for(int i=2; i<MAXN; i++) eh_primo[i] = 1;
    for(int i=2; i<MAXN;i++){
        primes.push_back(i);
        for(int j=i*i; j<MAXN; j+=i) eh_primo[j] = 0;
    }
}

int32_t main()
{_
    
}