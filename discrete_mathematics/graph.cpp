#include <iomanip>
#include <ios>
#include <iostream>
#include <set>
#include <stack>
#include <string>
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

    void in() const {
        FOR(u, 0, n - 1) {
            cout << char(u + 'A') << ": ";
            for (auto [v, w] : adj[u])
                cout << (char(v + 'A')) << " ";
            cout << endl;
        }
        cout << endl;
    }

    void find_euler(char start = 'A') {
        if (!has_euler()) {
            cout << "Graph don't exist euler path or cycle !!!" << endl;
            return;
        }

        FOR(i, 0, n - 1) {
            cout << "deg(";
            cout << char(i + 'A') << ") = ";
            cout << degree[i] << endl;
        }

        cout << endl << "Euler cycle = ";
        vector<int> paths = this->euler(start - 'A');
        FOR(i, 0, paths.size() - 1) cout << char(paths[i] + 'A');
        cout << endl;
    }

    void find_hamilton(char c = 'A') {
        vector<bool> visited(n, false);
        vector<int> path;

        int start = c - 'A';
        visited[start] = true;
        path.push_back(start);

        if (hamilton(start, visited, path, 1)) {
            cout << "Hamiltonian = ";
            for (int v : path)
                cout << char(v + 'A');
            cout << char(start + 'A') << endl;

            if (adj[path.back()].count({path[0], 0})) {
                cout << "Also a Hamiltonian cycle" << endl;
            }
        } else {
            cout << "No Hamiltonian path found." << endl;
        }
    }

    void dijkstra_instep(int step, int active, vector<int> d,
                         vector<bool> &visited, vector<int> parent) {
        cout << left << setw(6) << step;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                cout << setw(8) << "-";
            } else {
                if (i == active) {
                    cout << setw(8) << "*";
                } else if (d[i] == INF)
                    cout << setw(8) << "(IF," + string(1, char('A' + i)) + ")";
                else {
                    string cell = "(" + to_string(d[i]) + "," +
                                  string(1, char('A' + parent[i])) + ")";
                    cout << setw(8) << cell;
                }
            }
        }

        cout << setw(8) << char(active + 'A');
        if (active == parent[active])
            cout << setw(8) << "Empty" << endl;
        else {
            string cell = string(1, char(parent[active] + 'A')) +
                          string(1, char(active + 'A'));
            cout << setw(8) << cell << endl;
        }

        // mark vertex visited
        visited[active] = true;
    }

    void dijkstra(char c = 'A') {
        int start = c - 'A';
        int step = 0;
        vector<int> d(n, INF);
        vector<bool> visited(n, false);
        vector<int> parent(n);

        FOR(i, 0, n - 1) parent[i] = i;
        d[start] = 0;

        for (auto [v, w] : adj[start]) {
            d[v] = w;
            parent[v] = start;
        }

        cout << left << setw(6) << "Step";
        for (int i = 0; i < n; ++i)
            cout << setw(8) << char('A' + i);

        cout << setw(8) << "Vertex";
        cout << setw(8) << "Edge" << endl;
        dijkstra_instep(step++, start, d, visited, parent);

        FOR(i, 0, n - 2) {
            int u = 0;
            int mn = INF;

            FOR(i, 0, n - 1) {
                if (visited[i])
                    continue;

                if (d[i] < mn) {
                    mn = d[i];
                    u = i;
                }
            }

            for (auto [v, w] : adj[u]) {
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    parent[v] = u;
                }
            }

            dijkstra_instep(step++, u, d, visited, parent);
        }

        cout << endl;
        FOR(i, 0, n - 1) {
            if (i == start)
                continue;

            // path each vertex
            vector<char> path;
            int v = i;
            while (v != start) {
                v = parent[v];
                path.push_back(char(v + 'A'));
            }

            cout << "Path " << char(i + 'A') << ": ";
            FORD(i, path.size() - 1, 0) cout << path[i];
            cout << char(i + 'A') << " -> " << d[i] << endl;
        }
    }

    void prim_instep(int step, int active, vector<int> d, vector<bool> &visited,
                     vector<int> parent) {
        cout << left << setw(6) << step;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                cout << setw(8) << "-";
            } else {
                if (i == active) {
                    cout << setw(8) << "*";
                } else if (d[i] == INF || d[i] == -INF)
                    cout << setw(8) << "(IF," + string(1, char('A' + i)) + ")";
                else {
                    string cell = "(" + to_string(d[i]) + "," +
                                  string(1, char('A' + parent[i])) + ")";
                    cout << setw(8) << cell;
                }
            }
        }

        cout << setw(8) << char(active + 'A');
        if (active == parent[active])
            cout << setw(8) << "Empty" << endl;
        else {
            string cell = string(1, char(parent[active] + 'A')) +
                          string(1, char(active + 'A'));
            cout << setw(8) << cell << endl;
        }

        // mark vertex visited
        visited[active] = true;
    }

    void prim(char c = 'A', bool is_max = false) {
        int start = c - 'A';

        int step = 0;
        vector<int> d(n);
        FOR(i, 0, n - 1) d[i] = is_max ? -INF : INF;

        vector<bool> visited(n, false);
        vector<int> parent(n);

        FOR(i, 0, n - 1) parent[i] = i;
        d[start] = 0;

        for (auto [v, w] : adj[start]) {
            d[v] = w;
            parent[v] = start;
        }

        cout << left << setw(6) << "Step";
        for (int i = 0; i < n; ++i)
            cout << setw(8) << char('A' + i);

        cout << setw(8) << "Vertex";
        cout << setw(8) << "Edge" << endl;
        prim_instep(step++, start, d, visited, parent);

        vector<Edge> mst;

        FOR(i, 0, n - 2) {
            int u = 0;
            int mn = is_max ? -INF : INF;

            FOR(i, 0, n - 1) {
                if (visited[i])
                    continue;

                if (is_max) {
                    if (d[i] > mn) {
                        mn = d[i];
                        u = i;
                    }
                } else {
                    if (d[i] < mn) {
                        mn = d[i];
                        u = i;
                    }
                }
            }
            mst.push_back({parent[u], u, d[u]});

            for (auto [v, w] : adj[u]) {
                if (is_max) {
                    if (d[v] < w) {
                        d[v] = w;
                        parent[v] = u;
                    }
                } else {
                    if (d[v] > w) {
                        d[v] = w;
                        parent[v] = u;
                    }
                }
            }

            prim_instep(step++, u, d, visited, parent);
        }

        int sum = 0;
        cout << endl << "Spaning tree: " << endl;
        for (auto [u, v, w] : mst) {
            cout << char(u + 'A') << " " << char(v + 'A') << " " << w << endl;
            sum += w;
        }

        cout << "Sum: " << sum << endl;
    }
};

Graph input() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    FOR(i, 0, m - 1) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        edges.push_back({int(u - 'A'), int(v - 'A'), w});
    }

    Graph graph(n, m, edges);
    return graph;
}

// 10 20
// A B 2
// A C 6
// A E 1
// A F 10
// B C 9
// B D 12
// B I 4
// C D 2
// C J 20
// D E 2
// D G 1
// E F 3
// E G 6
// F I 5
// F H 8
// G H 10
// G J 3
// H I 2
// H J 1
// I J 3

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Graph graph = input();
    // graph.in();
    // graph.find_euler('E');
    // graph.find_hamilton();
    // graph.dijkstra('C');
    // graph.prim('A', true);
    return 0;
}
