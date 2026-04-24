#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problema: Periodicidade em Árvore de Estados Quânticos
 * Técnica: DFS + Autômato de KMP
 * Complexidade: O(N * 26)
 */

const int MAXN = 100005;
vector<int> adj[MAXN];
char edge_char[MAXN];
int pi[MAXN];
int aut[MAXN][26];
int max_period = 0;

void dfs(int u, int depth) {
    // 1. Cálculo da periodicidade para o estado atual
    if (depth > 0) {
        int L = depth;
        int longest_prefix_suffix = pi[L];
        int k = L - longest_prefix_suffix;

        // Regra: L deve ser divisível por k e repetir pelo menos 2 vezes (L >= 2k)
        if (L % k == 0 && L >= 2 * k) {
            if (k > max_period) max_period = k;
        }
    }

    // 2. Explorar os filhos
    for (int v : adj[u]) {
        int c = edge_char[v] - 'a';

        // O pi do próximo nível é determinado pelo autômato no estado atual
        pi[depth + 1] = aut[pi[depth]][c];

        // Backup da linha do autômato para permitir o rollback na DFS
        // Isso evita que ramos diferentes da árvore interfiram entre si
        int backup[26];
        for (int i = 0; i < 26; i++) backup[i] = aut[depth + 1][i];

        // Construção da próxima linha do autômato baseada no caractere da aresta
        for (int i = 0; i < 26; i++) {
            if (i == c) {
                aut[depth + 1][i] = depth + 1;
            } else {
                aut[depth + 1][i] = aut[pi[depth + 1]][i];
            }
        }

        dfs(v, depth + 1);

        // Rollback: Restaura o estado do autômato para o próximo vizinho de 'u'
        for (int i = 0; i < 26; i++) aut[depth + 1][i] = backup[i];
    }
}

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Lendo as conexões (pais)
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    // Lendo os caracteres das arestas
    string s;
    cin >> s;
    for (int i = 0; i < N - 1; i++) {
        edge_char[i + 2] = s[i];
    }

    // Inicialização do autômato para o estado vazio (raiz)
    pi[0] = 0;
    for (int i = 0; i < 26; i++) {
        aut[0][i] = 0;
    }

    // Inicia a busca a partir da raiz (nó 1, profundidade 0)
    dfs(1, 0);

    cout << max_period << endl;

    return 0;
}