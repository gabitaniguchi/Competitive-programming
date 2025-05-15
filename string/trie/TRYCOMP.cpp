#include <bits/stdc++.h>

using namespace std;

struct Trie{
    int child[26];
    int quantos = 0;
    string best = "";
    bool end = false;

    Trie(){
        fill(child, child+26, -1);
    }

};

vector<Trie> trie(1);
map<string, int> freq;

void add_string(string const& s){
    int v = 0;
    for(auto ch: s){
        int c = ch-'a';
        if(trie[v].child[c]==-1) {
            trie[v].child[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].child[c];

        int f = freq[s];
        if(f > trie[v].quantos || (f==trie[v].quantos && s<trie[v].best)){
            trie[v].best = s;
            trie[v].quantos = f;
        }
    }
    trie[v].end = true;
}

string query( string const& s){
    int v = 0;
    for(auto ch: s){
        int c = ch-'a';
        if(trie[v].child[c]==-1) return "";
        v = trie[v].child[c];
    }

    return trie[v].best;
}

int main(){

    int w, q;
    cin>>w;
    string s;

    while(w--){
        cin>>s;
        freq[s] ++;
        add_string(s);
    }

    cin>>q;

    while(q--){
        cin>>s;
        string ans;
        ans = query(s);
        if(ans == "") cout<<-1<<endl;
        else cout<<ans<<" "<<freq[ans]<<endl;
    }

    return 0;
}