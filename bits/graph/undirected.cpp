#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

class Graph {
private:
    static const int MAX = 1001;
    vector<int> adj[MAX];
    bool visited[MAX];
    int n, m;

    void inner_dfs(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v])
                inner_dfs(v);
        }
    }

    void inner_bfs(int s) {
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

public:
    Graph(int n, int m, vector<int> adj[]) {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n; i++) {
            this->adj[i] = adj[i];
        }
    }

    vector<int> dfs(int s) {}
};

int main() {
    SETUP;

    return 0;
}