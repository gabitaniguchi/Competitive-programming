#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n, sum;
    cin>>n>>sum;

    long long int v[n+5];
    long long int temp=0, ans=0;

    for(int i=1;i<=n;i++) cin>>v[i];

    long long int l=1;

    for(long long int r=1; r<=n; r++){
        temp += v[r];
        while (temp > sum){
            temp -= v[l];
            l++;
        }
        ans = max(ans, r-l+1);
    }

    cout<<ans<<endl;

    return 0;
}