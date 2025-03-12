#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2*1e5 + 10)

int n,m, k, pai[MAX], peso[MAX];
pair<int,int> vertices[MAX];
string question[MAX];
stack<string> ans;

int find(int x){
    if(pai[x]==x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(peso[a]>peso[b]) pai[b] = a;
    else if(peso[a]<peso[b]) pai[a] = b;

    else{
        pai[a] = b;
        peso[b] ++;
    }
}

int main(){

    scanf("%d%d%d", &n,&m,&k);

    while(m--){
        int a,b;
        scanf("%d%d", &a,&b);
    }

    for(int i=1;i<=k;i++){
        int a,b;
        cin>>question[i];
        scanf("%d%d", &a,&b);
        vertices[i] = {a,b};
    }

    for(int i=1;i<=n;i++){
        pai[i] = i;
        peso[i] = 1;
    }

    for(int i=k;i>=1;i--){
        int a = vertices[i].first;
        int b = vertices[i].second;

        if(question[i]=="ask"){
            if(find(a)==find(b)) ans.push("YES");
            else ans.push("NO");
        }

        else join(a,b);
    }

    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }

}