#include <ios>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
using namespace std;

#define ms(s, n)      memset(s, n, sizeof(s))
#define all(a)        a.begin(), a.end()
#define sz(a)         int((a).size())
#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

#define PB push_back
#define MP make_pair
#define F  first
#define S  second

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 1;
const int DEG = (int) 10001;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

struct Edge {
    int u;
    int v;
    int w;
};

class Graph {
private:
    int n, m, degree[DEG];
    set<pi> adj[DEG];
    bool visited[DEG];

    pair<vector<Edge>, int> prim(int start, bool is_max = false) {
        ms(visited, false);
        using T = tuple<int, int, int>;

        auto cmp_min = [](const T &a, const T &b) { return a > b; };
        auto cmp_max = [](const T &a, const T &b) { return a < b; };

        priority_queue<T, vector<T>, function<bool(T, T)>> pq(is_max ? cmp_max
                                                                     : cmp_min);
        visited[start] = true;

        for (auto &[v, w] : this->adj[start]) {
            if (!visited[v])
                pq.push({w, start, v});
        }

        vector<Edge> mst;
        int d = 0;

        while (!pq.empty()) {
            auto [w, from, to] = pq.top();
            pq.pop();

            if (!visited[to]) {
                d += w;
                visited[to] = true;
                mst.push_back({from, to, w});

                for (auto &[v, weight] : adj[to]) {
                    if (!visited[v])
                        pq.push({weight, to, v});
                }
            }
        }

        return {mst, d};
    }

    bool has_euler() {
        int odd = 0;
        FOR(i, 0, n - 1) {
            if (degree[i] & 1)
                odd += 1;
        }

        return (odd == 0) || (odd == 2);
    }

    vector<int> euler(int start) {
        stack<int> st;
        vector<int> path;
        st.push(start);

        while (!st.empty()) {
            int u = st.top();
            if (!adj[u].empty()) {
                auto [v, w] = *adj[u].begin();
                st.push(v);
                adj[u].erase({v, w});
                adj[v].erase({u, w});
            } else {
                st.pop();
                path.push_back(u);
            }
        }

        return path;
    }

    bool hamilton(int u, vector<bool> &visited, vector<int> &path, int count) {
        if (count == n) {
            if (adj[u].count({path[0], 0}))
                return true;
            return true;
        }

        for (auto &[v, w] : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                path.push_back(v);
                if (hamilton(v, visited, path, count + 1))
                    return true;
                path.pop_back();
                visited[v] = false;
            }
        }

        return false;
    }

    void dijkstra(int start) {
        vector<int> d(n, INF);
        vector<int> parent(n, 0);

        d[start] = 0;
        priority_queue<pi, vii, greater<pi>> pq;
        pq.push(MP(0, start));

        while (!pq.empty()) {
            auto [dics, u] = pq.top();
            pq.pop();

            if (dics > d[u])
                continue;

            for (auto [weight, v] : adj[u]) {
                if (d[v] > d[u] + weight) {
                    d[v] = d[u] + weight;
                    pq.push(MP(d[v], v));
                }
            }
        }

        FOR(i, 0, n - 1) cout << d[i] << " ";
        cout << endl;
    }

public:
    Graph(int n, int m, vector<Edge> edges, bool directed = false) {
        this->n = n;
        this->m = m;

        for (auto &[u, v, w] : edges) {
            adj[u].insert({v, w});
            adj[v].insert({u, w});

            degree[u]++;
            degree[v]++;
        }
    }

    Graph(Graph &graph) : n(graph.n), m(graph.m) {
        FOR(i, 0, n - 1) {
            adj[i] = graph.adj[i];
            degree[i] = graph.degree[i];
        }
    }

    void minimum_spaning_tree(int start) {
        auto [mst, d] = this->prim(start);

        cout << d << endl;
        for (auto &[u, v, w] : mst) {
            cout << u << " ";
            cout << v << " ";
            cout << w << endl;
        }
    }

    void maximum_spaning_tree(int start) {
        auto [mst, d] = this->prim(start, true);

        cout << d << endl;
        for (auto &[u, v, w] : mst) {
            cout << u << " ";
            cout << v << " ";
            cout << w << endl;
        }
    }

    void find_euler() {
        if (!has_euler()) {
            cout << "Graph don't exist euler path or cycle !!!" << endl;
            return;
        }
        vector<int> paths = this->euler(4);
        FOR(i, 0, paths.size() - 1) cout << paths[i] << " ";
        cout << endl;
    }

    void find_hamilton(int start = 0) {
        vector<bool> visited(n, false);
        vector<int> path;

        visited[start] = true;
        path.push_back(start);

        if (hamilton(start, visited, path, 1)) {
            cout << "Hamiltonian path found: ";
            for (int v : path)
                cout << v << " ";
            cout << endl;

            if (adj[path.back()].count({path[0], 0})) {
                cout << "Also a Hamiltonian cycle" << endl;
            }
        } else {
            cout << "No Hamiltonian path found." << endl;
        }
    }
};

Graph input() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    FOR(i, 0, m - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    Graph graph(n, m, edges);
    return graph;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Graph graph = input();
    // graph.minimum_spaning_tree(1);
    // graph.maximum_spaning_tree(1);
    // graph.find_euler();
    graph.find_hamilton();
    return 0;
}
