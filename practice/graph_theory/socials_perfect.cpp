#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Socials Perfect
 *
 * input:
 *      N, M
 *      1 <= N,M <= 1000
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          4 3
 *          1 3
 *          3 4
 *          1 4
 *      output:
 *          YES
 */

int n, m, count_comp;
vector<int> adj[1001];
bool visited[1001];
vector<int> comp;

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ms(visited, false);
}

void dfs(int u) {
    comp.push_back(u);
    count_comp++;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    SETUP;
    int TC;
    cin >> TC;
    while (TC--) {
        input();

        bool ok = true;
        REP(i, 1, n) {
            count_comp = 0;
            if (!visited[i]) {
                comp.clear();
                dfs(i);
                for (int x : comp) {
                    if (adj[x].size() != count_comp - 1) {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok)
                break;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}