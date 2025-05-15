#include <bits/stdc++.h>

using namespace std;

struct Trie{
    int child[26];
    int quantos = 0;
    bool end = false;

    Trie(){
        fill(child, child+26, -1);
    }

};

vector<Trie> trie(1);

void add_string(string const& s){
    int v = 0;
    for(auto ch: s){
        int c = ch-'a';
        if(trie[v].child[c]==-1) {
            trie[v].child[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].child[c];
        trie[v].quantos ++;
    }
    trie[v].end = true;
}

int search( string const& s){
    int v = 0;
    for(auto ch: s){
        int c = ch-'a';
        if(trie[v].child[c]==-1) return 0;
        v = trie[v].child[c];
    }
    return trie[v].quantos;
    
}

int main(){

    int w, q;
    cin>>w>>q;
    string s;

    while(w--){
        cin>>s;
        add_string(s);
    }

    while(q--){
        cin>>s;
        cout<<search(s)<<endl;
    }

    return 0;
}