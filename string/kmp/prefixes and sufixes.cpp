#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5+10)
#define int long long

string s;
int pi[MAX], sum[MAX], cnt[MAX], vis[MAX];
vector<pair<int,int>> ans;
vector<int> g[MAX];

void prefix_function(){
    for(int i=1, j=0; i<(int)s.size(); i++){
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;    
        cnt[pi[i]] ++;
        g[pi[i]].push_back(i);
        if(s[i]==s[i-pi[i]]-1) g[i].push_back(pi[i]);
    }
}

void dfs(int x){
    vis[x] = 1;

    if(g[x].empty()) {
        sum[x] = cnt[x];
        return;
    }

    sum[x] = cnt[x];

    for(auto next: g[x]){
        if(vis[next]) continue;
        dfs(next);
        sum[x] += sum[next];
    }
    
}

void solve(){
    int j = pi[(int)s.size()-1];

    while(j>0){
        int len = j;
        int times = sum[len]+1;

        ans.push_back({len,times});
        j = pi[j-1];
    }

    ans.push_back({(int)s.size(), 1});
}


int32_t main(){

    cin>>s;
    prefix_function();
    dfs(0);
    solve();
    for(int i=0;  i<(int)s.size();i++) cout<<pi[i]<<" ";
    cout<<endl;

    sort(ans.begin(), ans.end());
    
    cout<<(int)ans.size()<<endl;
    for(auto x: ans){
        int len = x.first, times = x.second;
        cout<<len<<" "<<times<<endl;
    }

    return 0;
}