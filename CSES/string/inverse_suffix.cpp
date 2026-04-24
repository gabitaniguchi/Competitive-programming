#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

int32_t main()
{_
    int n; cin>>n;
    vector<int> v(n+5), inv(n+5);
    vector<char> ans(n+5);
    char c = 'a';
    bool pos=true;

    for(int i=1; i<=n; i++){
        cin>>v[i];
        inv[v[i]] = i;
    }

    for(int i=1; i<=n; i++){
        if(i==1) ans[v[i]] = c;
        else if (inv[v[i-1]+1]<inv[v[i]+1]){
            ans[v[i]] = c;
        }
        else {
            c++;
            if(c>'z') pos=false;
            ans[v[i]] = c;
        }
    }

    if(!pos) cout<<-1<<endl;
    else{
        for(int i=1; i<=n; i++) cout<<ans[i];
        cout<<endl;
    }
    
}