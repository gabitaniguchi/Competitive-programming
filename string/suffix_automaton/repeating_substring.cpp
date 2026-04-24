#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5 + 5)

struct state {
    int len, link, first_pos;
    int min_pos, max_pos;
    map<char, int> next; 
};

struct Ans{
    int len, first_pos;
};

Ans ans;
state sam[2 *MAXN];
int sz, last;

void sam_init() {
    for(int i=0; i < 2 * MAXN; i++) {
        sam[i].next.clear();
        sam[i].min_pos = 2e18;
        sam[i].max_pos = -1;
    }
    sam[0].len = 0;
    sam[0].link = -1;
    sz = 1;
    last = 0;
    ans.len = 0;
}

void sam_add(char c, int pos) {
    int cur = sz++;
    sam[cur].len = sam[last].len + 1;
    sam[cur].first_pos = pos;
    sam[cur].min_pos = sam[cur].max_pos = pos;
    
    int p = last;
    while (p != -1 && !sam[p].next.count(c)) {
        sam[p].next[c] = cur;
        p = sam[p].link;
    }
    if (p == -1) {
        sam[cur].link = 0;
    } else {
        int q = sam[p].next[c];
        if (sam[p].len + 1 == sam[q].len) {
            sam[cur].link = q;
        } else {
            int clone = sz++;
            sam[clone].len = sam[p].len + 1;
            sam[clone].next = sam[q].next;
            sam[clone].link = sam[q].link;
            sam[clone].first_pos = sam[q].first_pos;
            sam[clone].min_pos = 2e18; // Clones não "nascem" com posição própria
            sam[clone].max_pos = -1;
            while (p != -1 && sam[p].next[c] == q) {
                sam[p].next[c] = clone;
                p = sam[p].link;
            }
            sam[q].link = sam[cur].link = clone;
        }
    }
    last = cur;
}

void precompute_positions() {
    // Ordenar estados por tamanho (decrescente) para subir na árvore de links
    vector<int> nodes(sz);
    iota(nodes.begin(), nodes.end(), 0);
    sort(nodes.begin(), nodes.end(), [](int a, int b) {
        return sam[a].len > sam[b].len;
    });

    for (int v : nodes) {
        if (sam[v].link != -1) {
            int p = sam[v].link;
            sam[p].min_pos = min(sam[p].min_pos, sam[v].min_pos);
            sam[p].max_pos = max(sam[p].max_pos, sam[v].max_pos);

            if(sam[p].max_pos > sam[p].min_pos){
                if(sam[p].len>ans.len) {
                    ans.len = sam[p].len;
                    ans.first_pos = sam[p].first_pos;
                }
            }
        }
    }
}

int32_t main() {_
    string s; cin >> s;
    sam_init();
    for(int i=0; i < s.size(); i++) sam_add(s[i], i);
    
    precompute_positions();

    if(ans.len==0) cout<<-1;
    for(int i=ans.first_pos-ans.len+1; i<=ans.first_pos; i++){
        cout<<s[i];
    }
    cout<<endl;
}