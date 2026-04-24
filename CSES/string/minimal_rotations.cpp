#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

int32_t main()
{_
    string s; cin>>s;
    s+=s;

    int ans=0, prev=0;

    for(int i=1; i<s.size()/2;i++){
        //cout<<" i "<<i<<" ans "<<ans<<endl;
        if(s[i]<s[ans]){
            ans = i;
        }
        else if(s[i]==s[ans]){
            int temp = ans+1, temp2=i;
            i++;
            //cout<<" temp "<<temp<<" i "<<i<<endl;
            while(s[temp]==s[i] && i<s.size()) {
                i++; temp++;
            }
            //cout<<" temp2 "<<temp<<" i2 "<<i<<endl;
            if(s[i]<s[temp2]) ans = i;
            else if(s[i]<s[temp]) ans=temp2;
            //cout<<"   ans "<<ans<<endl;
            i = temp2;
        }
    }

    for(int i=1; i<=s.size()/2;i++) {
        cout<<s[ans];
        ans++;
    }
    cout<<endl;
    
}