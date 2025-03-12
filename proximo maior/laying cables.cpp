#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(2e5 + 10)

int n, prox[MAX], ant[MAX];
pair<int, int> city[MAX];
int const inf = 1e9+10;
map <pair<int,int>, int> pos;
map <pair<int,int>, int> answer;
queue<pair<int,int>> fila;

void anterior_maior(){
    city[0] = {0,inf};

    for(int i=1; i<=n; i++){
        ant[i] = i-1;
        while(city[i].second > city[ant[i]].second) ant[i] = ant[ant[i]];
    }
}

void proximo_maior(){
    city[n+1] = {0,inf};
    for(int i=n; i>=1; i--){
        prox[i] = i+1;
        while(city[i].second > city[prox[i]].second) prox[i] = prox[prox[i]];
    }
}

int main(){

    cin>>n;

    for(int i=1; i<=n; i++){
        int d, tam;
        cin>>d>>tam;

        city[i] = {d,tam};
        pos[city[i]] = i;
        fila.push(city[i]);
    }

    sort(city+1, city+n+1);

    proximo_maior();
    anterior_maior();

    for(int i=1; i<=n; i++){

        int ans;

        if(prox[i]==n+1 && ant[i]==0) ans = -1;
        else if(prox[i]==n+1) ans = pos[{city[ant[i]].first,city[ant[i]].second}];
        else if(ant[i]==0) ans = pos[{city[prox[i]].first,city[prox[i]].second}];
        else{
            if(abs(city[i].first-city[ant[i]].first) < abs(city[i].first-city[prox[i]].first)) ans = pos[{city[ant[i]].first,city[ant[i]].second}];
            else if(abs(city[i].first-city[ant[i]].first) > abs(city[i].first-city[prox[i]].first)) ans = pos[{city[prox[i]].first,city[prox[i]].second}];
            else if(city[ant[i]].second>city[prox[i]].second) ans = pos[{city[ant[i]].first,city[ant[i]].second}];
            else ans = pos[{city[prox[i]].first,city[prox[i]].second}];
        }

        answer[{city[i].first, city[i].second}] = ans;
    }

    while(!fila.empty()){
        cout<<answer[fila.front()]<<" ";
        fila.pop();
    }

    cout<<endl;

    return 0;
}