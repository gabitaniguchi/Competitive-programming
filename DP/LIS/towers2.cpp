#include <bits/stdc++.h>

using namespace std;

#define MAX (int)(2e5 + 10)
#define INF (int)(1e15)

int v[MAX], n, ans=0;
multiset<int> cubo;

int main(){
    
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>v[i];
        if(i==1) 
            cubo.insert(v[i]);
        
        else{
            auto it = cubo.upper_bound(v[i]);
            if(it == cubo.end()) cubo.insert(v[i]);
            else{
                cubo.erase(it);
                cubo.insert(v[i]);
            }
        }
    }

    cout<<cubo.size()<<endl;

    return 0;
}