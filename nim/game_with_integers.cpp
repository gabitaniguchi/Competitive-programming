#include <bits/stdc++.h>
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
  

int32_t main()
{_
    int t;
    cin>>t;

    while(t--){
        int x;cin>>x;

        if(x%3==1 || x%3==2) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    
}