#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define INF (int)(1e18)

vector<int> prefix_function(vector<int>& p){
    vector<int> pi(p.size());
    for(int i=1, j=0; i<(int)p.size(); i++){
        while(j>0 && p[j]!=p[i]) j = pi[j-1];
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main()
{_
    int n, w, ans=0; cin>>n>>w;

    vector<int> v(n+5), e(w+5), s;

    for(int i=1; i<=n; i++) cin>>v[i];
    for(int i=1; i<=w; i++) cin>>e[i];

    if(w==1){
        cout<<n<<endl;
        return 0;
    }

    for(int i=2; i<=w; i++) s.push_back(e[i]-e[i-1]);

    s.push_back(INF);

    for(int i=2; i<=n; i++) s.push_back(v[i]-v[i-1]);
    
    vector<int> pi = prefix_function(s);
    for(int i=w+1; i<pi.size();i++){
        if(pi[i]==w-1) ans++;
    }

    cout<<ans<<endl;

}
