#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define P 31
#define MOD (int)(1e9+9)

int compute_hash(string const& s) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return hash_value;
}

int32_t main()
{_
    string s, t;
    cin>>s>>t;

    cout<<compute_hash(s)<<endl;
    cout<<compute_hash(t)<<endl;
}
