#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Spanning Tree BFS
 *
 * input:
 *      N, M, s
 *      1 <= s <= n <= 1000
 *      1 <= m <= n*(n - 1)/2
 *
 * output: print all edge in spanning tree
 *
 * @example
 *      input:
 *          7 12 3
 *          6 3
 *          6 2
 *          5 3
 *          5 4
 *          7 3
 *          5 2
 *          7 1
 *          4 3
 *          2 1
 *          6 4
 *          7 2
 *          3 2
 *      output:
 *          3->2
 *          2->1
 *          1->7
 *          2->5
 *          5->4
 *          4->6
 */

int n, m, s;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m >> s;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    REP(i, 1, n) sort(all(adj[i]));
    ms(visited, false);
}

void bfs() {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                cout << u << "->" << v << endl;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    SETUP;

    input();
    bfs();

    return 0;
}
