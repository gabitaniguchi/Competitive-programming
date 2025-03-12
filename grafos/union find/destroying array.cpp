#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e5 + 10)

int n, pai[MAX];
long long int v[MAX], sum[MAX], ans=0;
bool foi[MAX];
stack<long long int> erase, resp;

int find(int x){
    if(pai[x]==x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x), y= find(y);
    
    if(x==y) return;
    if(sum[x]> sum[y]) swap(x,y);

    pai[y] = x;
    sum[x] += sum[y];
    ans = max(ans, sum[x]);
}

int main(){

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        pai[i] = i;
        foi[i] = false;
    }

    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if(i!=1) erase.push(x);
    }

    resp.push(0);

    while(!erase.empty()){

        int pos = erase.top();
        erase.pop();

        sum[pos] = v[pos];
        foi[pos] = true;
        if(foi[pos-1]) join(pos-1, pos);
        if(foi[pos+1]) join(pos, pos+1);
        else ans = max(ans, v[pos]);

        resp.push(ans);
    }

    while(!resp.empty()){
        long long int atual = resp.top();
        cout<<atual<<endl;
        resp.pop();
    }

    return 0;
}