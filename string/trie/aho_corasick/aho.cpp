#include <bits/stdc++.h>

using namespace std;
#define k 26
#define MAXN (int)(1e5+10)

struct Trie{
    int child[k];
    bool end = false;
    int link = -1;
    int output = -1;

    Trie(){
        fill(child, child+k, -1);
    }
};

vector<Trie> trie(1);
// frequencia de todos os padrões acima de i
int freqacumulada[MAXN];

void build(){
    queue<int>q;

    //define os links e os outputs da camada 1
    for(auto c: trie[0].child){
        if(c!=-1) {
            trie[c].link = 0;
            trie[c].output = trie[c].end? c : -1;
            q.push(c);
        }
    }

    while(!q.empty()){
        int atual = q.front();
        q.pop();

        for(int c=0; c<k; c++){
            int next = trie[atual].child[c];
            if(next==-1) continue;
            
            int suf_link = trie[atual].link;

            // enquanto não acho um failure link válido, subo na Trie
            while(suf_link!=0 && trie[suf_link].child[c]==-1){
                suf_link = trie[suf_link].link;
            }
            
            // se achei um sufixo válido, aponto para ele
            if(trie[suf_link].child[c]!=-1) 
                trie[next].link = trie[suf_link].child[c];

            // caso contrário, aponto para a raíz
            else
                trie[next].link = 0;

            // gera o output link
            int suf_next = trie[next].link;
            if(trie[suf_next].end) trie[next].output = suf_next;
            else trie[next].output = trie[suf_next].output;

            // Propaga a frequência dos padrões
            if (trie[next].output != -1) {
                freqacumulada[next] += freqacumulada[trie[next].output];
            }

            q.push(next);
        }
    }
}

void insert(string& s){
    int v=0;
    for(auto ch: s){
        int c = ch-'a';
        if(trie[v].child[c]==-1){
            trie[v].child[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].child[c];
    }
    trie[v].end = true;
    freqacumulada[v]++;
}

// retorna o somatório das ocorrências de todos os padrões
int query(string& s){
    int v=0, ans=0;
    for(auto ch: s){
        int c = ch-'a';

        // se não há transição direta, segue os failure links
        while(v!=0 && trie[v].child [c]==-1)
            v = trie[v].link;

        if(trie[v].child[c]!=-1)
            v = trie[v].child[c];

        ans += freqacumulada[v];
    }

    return ans;
}

int main(){

    int w, q;
    cin>>w;

    string s;

    while(w--){
        cin>>s;
        insert(s);
    }

    build();

    cin>>q;

    while(q--){
        cin>>s;
        cout<<query(s)<<endl;
    }

    return 0;
}
