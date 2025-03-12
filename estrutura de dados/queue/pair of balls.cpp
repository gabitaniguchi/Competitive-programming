#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(4e5 + 10)

int n,m,k;
queue <int> fila[MAX];
queue <pair<int,int>> tira;
map <int, int> dic;

int main(){

    cin>>n>>m;

    for(int i=1; i<=m; i++){
        cin>>k;

        for(int j=1; j<=k; j++){
            int x;
            cin>>x;

            fila[i].push(x);

            if(j==1) {
                if(dic.find(x) != dic.end()){
                    tira.push({dic[x], i});
                }
                else dic[x] = i;
            }
        }
    }

    int total = 2*n;

    while(!tira.empty()){
        
        int a = tira.front().first;
        int b = tira.front().second;
        tira.pop();

        total -= 2;
        if(total==0) break;

        fila[a].pop();
        fila[b].pop();

        int x=-1,y=-1;
        if(!fila[a].empty()) x = fila[a].front();
        if(!fila[b].empty()) y = fila[b].front();

        if(x!=-1){
            if(dic.find(x) != dic.end()){
                tira.push({dic[x], a});
            }
            else dic[x] = a;
        }

        if(y!=-1){
            if(dic.find(y) != dic.end()){
                tira.push({dic[y], b});
            }
            else dic[y] = b;
        }
    }

    if(total==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}