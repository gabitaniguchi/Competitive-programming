#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int vis[MAX];
int dc1[MAX], dc2[MAX], dq1[MAX], dq2[MAX];
int ponta1, maiord=0, maiorv=0;

vector <int> c[MAX], q[MAX];

void atualiza (){
    maiord = 0;
    memset (vis, 0, sizeof vis);
}

void circulo_ponta1 (int x){

    vis[x] = 1;

    for(int i=0;i<c[x].size();i++){

        int next = c[x][i];

        if(vis[next]>0) continue;

        dc1[next] = dc1[x] + 1;

        if(dc1[next] > maiord){
            maiord = dc1[next];
            maiorv = next;
        }
        
        circulo_ponta1 (next);
    }
}

void circulo_ponta2 (int x){

    vis[x] = 1;

    for(int i=0;i<c[x].size();i++){

        int next = c[x][i];

        if(vis[next]>0) continue;

        dc2[next] = dc2[x] + 1;

        if(dc2[next] > maiord){
            maiord = dc2[next];
            maiorv = next;
        }
        
        circulo_ponta2 (next);
    }
}

void quadrado_ponta1 (int x){

    vis[x] = 1;

    for(int i=0;i<q[x].size();i++){

        int next = q[x][i];

        if(vis[next]>0) continue;

        dq1[next] = dq1[x] + 1;

        if(dq1[next] > maiord){
            maiord = dq1[next];
            maiorv = next;
        }
        
        quadrado_ponta1 (next);
    }
}

void quadrado_ponta2 (int x){

    vis[x] = 1;

    for(int i=0;i<q[x].size();i++){

        int next = q[x][i];

        if(vis[next]>0) continue;

        dq2[next] = dq2[x] + 1;

        if(dq2[next] > maiord){
            maiord = dq2[next];
            maiorv = next;
        }
        quadrado_ponta2 (next);
    }
}

int main(){

    int nc, nq;
    cin>>nc>>nq;

    for(int i=1;i<nc;i++){
        int a,b;
        cin>>a>>b;

        c[a].push_back(b);
        c[b].push_back(a);
    }

    for(int i=1;i<nq;i++){
        int a,b;
        cin>>a>>b;

        q[a].push_back(b);
        q[b].push_back(a);
    }

    circulo_ponta1(1);

    int ponta1 = maiorv;
    atualiza();
    memset(dc1, 0, sizeof dc1);

    circulo_ponta1(ponta1);
   
    int ponta2 = maiorv;
    atualiza();
    
    circulo_ponta2(ponta2);

    int menor = nc+5;
    int ans_c, ans_q;

    for(int i=1;i<=nc;i++){
        int diam = max (dc1[i], dc2[i]);

        if(diam <= menor){
            ans_c = i;
            menor = diam;
        }
    }

    atualiza();

    quadrado_ponta1(1);

    ponta1 = maiorv;
    atualiza();
    memset(dq1, 0, sizeof dq1);

    quadrado_ponta1(ponta1);
    
    ponta2 = maiorv;
    atualiza();
    
    quadrado_ponta2(ponta2);

    menor = nq+5;

    for(int i=1;i<=nq;i++){
        int diam = max (dq1[i], dq2[i]);

        if(diam <= menor){
            ans_q = i;
            menor = diam;
        }
    }
    
    cout<<ans_c<<" "<<ans_q<<endl;

    return 0;
}