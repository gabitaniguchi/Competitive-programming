#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SuffixAutomaton {
    struct State {
        int len;
        State *link;
        map<char, State *> next;
        int count;
    };

    State *first, *last;

    SuffixAutomaton(string s) {
        first = last = new State{};
        for (auto c : s) {
            auto *add = new State{};
            add->len = last->len + 1;
            add->link = first;
            State *cur = last;
            while (cur && !cur->next[c]) {
                cur->next[c] = add;
                cur = cur->link;
            }
            if (cur && cur->next[c] != add) {
                State *mid = cur->next[c];
                if (cur->len + 1 == mid->len) {
                    add->link = mid;
                } else {
                    auto *copy = new State(*mid);
                    copy->len = cur->len + 1;
                    add->link = mid->link = copy;
                    while (cur && cur->next[c] == mid) {
                        cur->next[c] = copy;
                        cur = cur->link;
                    }
                }
            }
            last = add;
        }
        dfs(first);
    }

    void dfs(State *cur) {
        if (cur->count) return;
        cur->count = 1;
        for (auto [c, p] : cur->next) {
            dfs(p);
            cur->count += p->count;
        }
    }
};

int32_t main() {
    string s;
    cin >> s;
    SuffixAutomaton sa(s);
    cout << sa.first->count - 1 << "\n";
}