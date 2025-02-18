#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Tom Cat
 *
 * input:
 *      N, M
 *      2 <= N <= 1000
 *      1 <= m <= n
 *
 * output: print maximum fish cat can be eat
 *
 * @example
 *      input:
 *          7 1
 *          1 0 1 1 0 0 0
 *          1 2
 *          1 3
 *          2 4
 *          2 5
 *          3 6
 *          3 7
 *      output:
 *          2
 */

int n, s, res, bug[1001];
vector<int> adj[1001];

void input() {
    cin >> n >> s;
    REP(i, 1, n) cin >> bug[i];
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
}

void dfs(int u, int p, int b) {
    if (bug[u])
        b++;
    else
        b = 0;

    if (b > s)
        return;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, b);
        }
    }

    if (b <= s && adj[u].size() == 1 && u != 1)
        res++;
}

int main() {
    SETUP;

    input();
    dfs(1, -1, 0);

    cout << res << endl;
    return 0;
}