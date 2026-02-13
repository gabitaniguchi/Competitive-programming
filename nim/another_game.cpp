#include <bits/stdc++.h>
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
  

int32_t main()
{_
    int t;
    cin>>t;

    while(t--){
        int n;cin>>n;
        bool first=false;

        for(int i=1; i<=n; i++){
            int x; cin>>x;
            if(x%2==1) first=true;
        }

        if(first) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }
}