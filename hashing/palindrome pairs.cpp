#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(1e5+10)

typedef long long ll;
int n;
string s;
map<int, int> mp;
int mask[28];

int main(){

    cin>>n;

    int ans = 0;

    for(int i=1; i<=n; i++){
        cin>>s;

        sort(s.begin(), s.end());
        for(auto t: s){
            mask[t-96] ++;
            mask[t-96] %= 2;
        }

        int bit=0;
        int base = 1;
        for(int i=1; i<=26; i++){
            bit += mask[i]*base;
            base*=10;
        }

        mp[bit]++;
        if(bit == 00000000000000000000000000) ans++;
    }






    return 0;
}