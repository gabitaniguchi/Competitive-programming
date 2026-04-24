#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);  
#define MAXN (int)(1e5+10)

struct state {
    int len, link, cnt;
    map<char, int> next;
};

state sam[2*MAXN];
int sz, last, ans[MAXN];

void sam_init() {
    sam[0].len = 0;
    sam[0].link = -1;
    sam[0].cnt = 0;
    sz++;
    last = 0;
}

void sam_add(char c) {
    int cur = sz++;
    sam[cur].len = sam[last].len + 1;
    sam[cur].cnt = 1;
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

void sam_build(string &s){
    sam_init();
    for(auto c:s) sam_add(c);
}

int32_t main()
{_
    string s; cin>>s;
    sam_build(s);

    for (int i = 1; i < sz; i++) {
        int shortest = sam[sam[i].link].len + 1;
        int longest = sam[i].len;
        
        ans[shortest]++;
        if (longest + 1 < MAXN) ans[longest + 1]--;
    }

    int current_count = 0;
    for (int i = 1; i <= s.size(); i++) {
        current_count += ans[i];
        cout << current_count << " ";
    }
    cout<<endl;
    
}