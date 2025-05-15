#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

struct Trie{
    int child[26];
    set<string> words;
    bool end = false;

    Trie(){
        fill(child, child+26, -1);
    }
};

vector<Trie> trie(1);

void add_string(string const& s){
    int v=0;
    for(auto ch: s){
        int c = ch-'a';

        if(trie[v].child[c]==-1){
            trie[v].child[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].child[c];
        trie[v].words.insert(s);
    }
    trie[v].end = true;
}

void query(string const& s){
    int v=0;
    for(auto ch: s){
        int c = ch-'a';

        if(trie[v].child[c]==-1){
            cout<<"No match."<<endl;
            return;
        }
        v = trie[v].child[c];
    }
    
    for(auto palavra: trie[v].words){
        if (palavra == s) continue;
        cout<<palavra<<endl;
    }
    return;
}

int main(){_

    int w, q;
    cin>>w;
    string s;

    while(w--){
        cin>>s;

        add_string(s);
    }

    cin>>q;
    for(int i=1; i<=q; i++){
        cin>>s;
        cout<<"Case #"<<i<<":"<<endl;
        query(s);
    }

    return 0;
}