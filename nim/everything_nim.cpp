#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> v;
        set<int> s;

        for(int i=1;i<=n;i++){
            int x;cin>>x;
            s.insert(x);
        }

        if(s.size()==1){
            cout<<"Alice"<<endl;
            continue;
        }
        
        for(auto x: s) v.push_back(x);
        
        if(s.size()==2){
            if(v[0]==1) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
            continue;
        }
         n = s.size();
        char prev;
        int last = v[n-2] - v[n-3];
        if(last==1) prev='L';
        else prev='W';

        for(int i=n-3; i>=0;i--){
            int last;
            if(i==0) last=v[0];
            else last = v[i]-v[i-1];

            if(last==1 && prev=='W') prev='L';
            else if(last==1 && prev=='L') prev='W';
            else if(last!=1) prev='W';
        }
        if(prev=='W') cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }


    return 0;
}