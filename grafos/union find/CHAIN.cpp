#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(5e4+10)

int t, n, k, pai[MAX], peso[MAX];
vector<int> g[MAX];
queue<int> limpar;

int find(int x){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x), y = find(y);

    if(peso[x]>peso[y]) pai[y] = x;
    else if(peso[y]>peso[x]) pai[x] = y;

    else{
        pai[x] = y;
        peso[y]++;
    }

}

bool invalid(int h, int a, int b){
    if(h==2 && a==b) return true;
    if(a>n || b>n) return true;
    if(find(a)==find(b) && h==2) return true;
    if(h==1){
        for(auto x: g[a]){
            if(x==b) return true;
        }
    }

    return false;
}

int main(){

    cin>>t;

    while(t--){
        cin>>n>>k;

        int ans = 0;

        while(!limpar.empty()){
            int atual = limpar.front();
            limpar.pop();

            g[atual].clear();
        }

        for(int i=1;i<=n;i++){
            pai[i] = i;
            peso[i] = 1;
        }

        while(k--){
            int h, a, b;
            cin>>h>>a>>b;

            if(invalid(h,a,b)) ans++;

            else{
                if(h==1) join(a,b);
                else{
                    g[a].push_back(b);
                    g[b].push_back(a);

                    limpar.push(a);
                    limpar.push(b);
                }
            }

        }

        cout<<ans<<endl;
    }

    return 0;
}
