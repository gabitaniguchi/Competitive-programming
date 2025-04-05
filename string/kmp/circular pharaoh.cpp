#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e6+10)
#define int long long
string s;
int pi[MAX], ans=0;

void prefix_function(){
    for(int i=1, j=0; i<(int)s.size();i++){
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
}


int32_t main(){
    
    cin>>s;
    prefix_function();
    int n = (int)s.size();

    for(int i=0; i<(int)s.size(); i++){
        if(pi[i]==0) continue;
        int k = n - pi[i];
        if(n%k==0) ans += n;
    }

    ans++;
    cout<<ans<<endl;

    return 0;
}