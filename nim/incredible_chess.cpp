#include <bits/stdc++.h>
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
  

int32_t main()
{_

    int t; cin>>t;

    for(int teste=1; teste<=t; teste++){
        int n; cin>>n;
        int ans = 0;
        vector<int> w,b;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            w.push_back(x);
        }

        for(int i=0;i<n;i++){
            int x; cin>>x;
            ans^= (x-w[i]-1);
        }

        cout<<"Case "<<teste<<": ";
        if(ans) cout<<"white wins"<<endl;
        else cout<<"black wins"<<endl;
    }
    
}