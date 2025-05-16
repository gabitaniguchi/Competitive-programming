#include <bits/stdc++.h>

using namespace std;
#define k 26
#define MAXN (int)(1e5+10)

struct Trie{
    int child[k];
    int end = 0;
    int link = -1;
    int output = -1;

    Trie(){
        fill(child, child+k, -1);
    }
};

vector<Trie> trie(1);

void build(){
    queue<int>q;

    //define os links e os outputs da camada 1
    for(int c=0; c<k; c++){
        int nxt = trie[0].child[c];
        if(nxt!=-1) {
            trie[nxt].link = 0;
            trie[nxt].output = trie[nxt].end? trie[nxt].link : -1;
            q.push(nxt);
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int c=0; c<k; c++){
            int nxt = trie[v].child[c];
            if(nxt==-1) continue;
            
            int suf_link = trie[v].link;

            // enquanto não acho um failure link válido, subo na Trie
            while(suf_link!=0 && trie[suf_link].child[c]==-1){
                suf_link = trie[suf_link].link;
            }
            
            // se achei um sufixo válido, aponto para ele
            if(trie[suf_link].child[c]!=-1) 
                trie[nxt].link = trie[suf_link].child[c];

            // caso contrário, aponto para a raíz
            else
                trie[nxt].link = 0;

            // gera o output link
            int suf_nxt = trie[nxt].link;
            // se chego em um final de padrão, tenho um novo output link
            if(trie[suf_nxt].end) trie[nxt].output = suf_nxt;
            else trie[nxt].output = trie[suf_nxt].output;

            q.push(nxt);
        }
    }
}

void insert(string& s, int idp){
    int v=0;
    for(auto ch: s){
        int c = ch-'a';
        if(trie[v].child[c]==-1){
            trie[v].child[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].child[c];
    }
    trie[v].end = idp;
}

// retorna a frequência de cada padrão
vector<int> query(string& s, int p){
    vector<int> freq(p+5);
    int v=0;
    for(auto ch: s){
        int c = ch-'a';

        // se não há transição direta, segue os failure links
        while(v!=-1 && trie[v].child[c]==-1)
            v = trie[v].link;

        if(trie[v].child[c]!=-1)
            v = trie[v].child[c];

        //cout<<v<<" "<<trie[v].output<<endl;

        for(int nxt = v; nxt!=-1; nxt=trie[nxt].output){
            if(trie[nxt].end) freq[trie[nxt].end]++;
            
        }

    }
    return freq;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        trie.clear();
        trie.emplace_back();
        string txt,s;
        cin>>txt;

        int w;
        cin>>w;

        for(int i=1; i<=w; i++){
            cin>>s;
            insert(s, i);
        }

        build();

        vector<int> freq = query(txt , w);
        //cout<<"i "<<endl;
        for(int i=1; i<=w; i++){
            cout<<freq[i]<<endl;
        }
    }

    return 0;
}
