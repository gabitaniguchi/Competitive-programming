#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> len(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        len[i] = min(r - i, len[l + (r - i)]);
        while(s[i - len[i]] == s[i + len[i]]) {
            len[i]++;
        }
        if(i + len[i] > r) {
            l = i - len[i], r = i + len[i];
        }
    }
    return vector<int>(begin(len) + 1, end(len) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

// Retorna tamanho do maior palindro centrado em i
int maior_len_i(int i, vector<int>& len) {
    // centro impar
    int odd = len[2*i]-1;
    int even = ((2*i+1) < len.size())? len[2*i+1]-1: 0;
    return max(even, odd);
}

int32_t main()
{_
    string s; cin>>s;
    vector<int> len = manacher(s);
    vector<int> ans(s.size()+5);

    for(int i=0; i<s.size();i++){
        int odd = len[2*i]-1;
        int idx = i + odd/2;
        ans[idx] =  max(ans[idx],odd);  

        int even = ((2*i+1) < len.size())? len[2*i+1]-1: 0;
        idx = i + even/2;
        ans[idx] =  max(ans[idx],even);  
    }

    for(int i=s.size();i>0;i--){
        if(ans[i]>2) ans[i-1]=max({ans[i-1], ans[i]-2,(int)1}); 
    }

    for(int i=0;i<s.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

