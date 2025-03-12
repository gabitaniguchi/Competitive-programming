#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e3 + 10)

vector<int> g[MAX];
int n,vis[MAX], e[MAX];
int const inf = 1e9+10;
queue<int> fila;
map<string,int> nome;
vector<pair<string,string>> autores_ordenado;

void ordena(set<string>s){
    string inicial, sobrenome;
    for(auto x: s){
        if(x=="P. Erdos") continue;
        inicial = x[0];
        inicial += ".";
        for(int i=3;i<(int)x.size();i++) sobrenome += x[i];

        autores_ordenado.push_back({sobrenome,inicial});
        sobrenome = "";
        inicial = "";
    }
    sort(autores_ordenado.begin(),autores_ordenado.end());
}

void quantos_erdos (int vertice){
    fila.push({vertice});
    vis[vertice] = 1;
    
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(auto next: g[atual]){
            if(vis[next]==1) continue;
            if(e[atual]!=inf)e[next] = e[atual]+1;
            vis[next] = 1;
            fila.push({next});
        }
    }

}

int main(){
    nome["P. Erdos"] = 1;
    int teste=1;
    
    while(true){
        cin>>n;
        if(n==0) break;
        cin.ignore();
        int temp=2;
        string a,b;
        set<string> autores;
        vector<int> entrada[n+5];

        for(int i=1;i<=n;i++){
            
            getline(cin,a);

            for(int j=0;j<(int)a.size();j++){
                if(a[j]==',' || j==(int)a.size()-1) {
                    autores.insert(b);

                    auto it = nome.find(b);
                    if(it == nome.end()){
                        nome[b] = temp;
                        temp++;  
                    }   
                    entrada[i].push_back(nome[b]);

                    b = "";
                    j++;
                }
                else if(j+1!=(int)a.size()) b+= a[j];
            }
        }

        for(int j=1;j<=n;j++){
            if((int)entrada[j].size()<2) continue;

            for(int q=0;q<(int)entrada[j].size();q++){
                int autor1 = entrada[j][q];
                for(int k=q+1; k<(int)entrada[j].size();k++){
                    int autor2 = entrada[j][k];
                    g[autor1].push_back(autor2);
                    g[autor2].push_back(autor1);
                }
            }
        }

        for(int j=2;j<=temp;j++) e[j] = inf;
        memset(vis,0,sizeof(vis));
        e[1] = 0;

        for(int j=1;j<=temp;j++){
            if(vis[j]!=1) quantos_erdos(j);
        }

        ordena(autores);

        printf("Teste %d\n", teste);
        for(auto x: autores_ordenado){
            cout<<x.second<<" "<<x.first<<": ";
            string completo = x.second + " " + x.first;
            if(e[nome[completo]]!=inf) cout<<e[nome[completo]]<<endl;
            else cout<<"infinito"<<endl;
        }

        cout<<endl;

        for(auto x: autores) if(x!="P. Erdos") nome.erase(x);
        for(int j=1;j<=temp;j++) g[j].clear();
        autores_ordenado.clear();

        teste ++;
    }

    return 0;
}