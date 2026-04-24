#include <bits/stdc++.h>
using namespace std;

int dp[105][105][105];
struct Parent {
    int i, j, k;
    char c; // Store character used: '0' for skip, else the actual char
} p[105][105][105];

int nxt[105][26];

// Robust Automaton: For each state k and char c, find the new length of prefix match
void build_automaton(string v) {
    int m = v.size();
    for (int i = 0; i < m; i++) {
        for (int c = 0; c < 26; c++) {
            string cur = v.substr(0, i) + (char)('A' + c);
            for (int len = min((int)cur.size(), m); len >= 0; len--) {
                if (cur.substr(cur.size() - len) == v.substr(0, len)) {
                    nxt[i][c] = len;
                    break;
                }
            }
        }
    }
}

int main() {
    string s, t, v;
    if (!(cin >> s >> t >> v)) return 0;

    int n = s.size(), m = t.size(), l = v.size();
    build_automaton(v);

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < l; k++) {
                if (dp[i][j][k] == -1) continue;

                // Option 1: Skip s[i]
                if (i < n && dp[i + 1][j][k] < dp[i][j][k]) {
                    dp[i + 1][j][k] = dp[i][j][k];
                    p[i + 1][j][k] = {i, j, k, '0'};
                }
                // Option 2: Skip t[j]
                if (j < m && dp[i][j + 1][k] < dp[i][j][k]) {
                    dp[i][j + 1][k] = dp[i][j][k];
                    p[i][j + 1][k] = {i, j, k, '0'};
                }
                // Option 3: Match s[i] and t[j]
                if (i < n && j < m && s[i] == t[j]) {
                    int nk = nxt[k][s[i] - 'A'];
                    if (nk < l && dp[i + 1][j + 1][nk] < dp[i][j][k] + 1) {
                        dp[i + 1][j + 1][nk] = dp[i][j][k] + 1;
                        p[i + 1][j + 1][nk] = {i, j, k, s[i]};
                    }
                }
            }
        }
    }

    int ans = 0, bk = -1;
    for (int k = 0; k < l; k++) {
        if (dp[n][m][k] > ans) {
            ans = dp[n][m][k];
            bk = k;
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
    } else {
        string res = "";
        int ci = n, cj = m, ck = bk;
        while (ci > 0 || cj > 0 || ck > 0) {
            Parent prev = p[ci][cj][ck];
            if (prev.c != '0') res += prev.c;
            ci = prev.i; cj = prev.j; ck = prev.k;
            if (ci == 0 && cj == 0 && ck == 0) break;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}