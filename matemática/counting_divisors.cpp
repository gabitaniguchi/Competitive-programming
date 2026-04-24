#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

#define MAXN (int)(1e6+10)
int eh_primo[MAXN];
vector<int> primes;
void crivo(){
    for(int i=2; i<MAXN; i++) eh_primo[i] = 1;
    for(int i=2; i<MAXN;i++){
        primes.push_back(i);
        for(int j=i*i; j<MAXN; j+=i) eh_primo[j] = 0;
    }
}

int count_divisors(int x){
    int div=1;
    if(eh_primo[x]) return 2;
    for(auto p:primes){
        if(p*p>x) break;
        int exp=0;
        while(x%p==0){
            x/=p;
            exp++;
        }
        if(exp>0) div*=(exp+1);
    }
    return div;
}


int32_t main()
{_
    int t; cin>>t;

    crivo();
    while(t--){
        int n; cin>>n;
        cout<<count_divisors(n)<<" ";
    }
}