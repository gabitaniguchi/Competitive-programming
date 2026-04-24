#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

struct state {
    int len, link, cnt, num_paths;
    map<char, int> next;
};

state sam[2*MAXN];
int sz, last;

void sam_init() {
    sam[0].len = 0;
    sam[0].link = -1;
    sam[0].cnt = 0;
    sam[0].num_paths = 0;
    sz++;
    last = 0;
}

void sam_add(char c) {
    int cur = sz++;
    sam[cur].len = sam[last].len + 1;
    sam[cur].cnt = 1;
    sam[cur].num_paths = 0;
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
            sam[clone].cnt = 0;
            while (p != -1 && sam[p].next[c] == q) {
                sam[p].next[c] = clone;
                p = sam[p].link;
            }
            sam[q].link = sam[cur].link = clone;
        }
    }
    last = cur;
}

void sam_count_freq(){
    vector<int> states_by_len;
    for(int i = 1; i < sz; i++) {
        if(sam[i].link!=-1)
            states_by_len.push_back(i);
    }
    
    sort(states_by_len.begin(), states_by_len.end(), [](int a, int b) {
        return sam[a].len > sam[b].len;
    });

    // Propaga: toda vez que uma string longa aparece, seus sufixos também aparecem
    for(int v : states_by_len) 
        sam[sam[v].link].cnt += sam[v].cnt;
}

// Função de DP para contar caminhos
// A partir do zero contém todos (inclusive a substring vazia)
int count_paths(int u) {
    if (sam[u].num_paths != 0) return sam[u].num_paths;
    int res = 0; // A própria string vazia/parada neste estado
    for (auto const& [c, v] : sam[u].next) {
        res += count_paths(v);
    }
    return sam[u].num_paths = res + sam[u].cnt;
}

void get_kth_substring(int k){
    sam[0].num_paths = count_paths(0);
    int state = 0;
    string ans = "";

    while(k>0){
        for(char c='a'; c<='z'; c++){
            int nxt_state = sam[state].next[c];
            if(nxt_state!=0){
                if(k <= sam[nxt_state].num_paths){
                    ans+=c;
                    k-=sam[nxt_state].cnt;
                    state = nxt_state;
                    break;
                }
                else k-=sam[nxt_state].num_paths;
            }
        }
    }
    cout<<ans<<endl;
}

void sam_build(string &s){
    sam_init();
    for(auto c:s) sam_add(c);
    sam_count_freq();
}

int32_t main()
{_
    string s; cin>>s;
    sam_build(s);

    int k; cin>>k;
    get_kth_substring(k);
}