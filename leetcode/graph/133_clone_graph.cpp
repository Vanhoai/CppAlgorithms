#include <iostream>
#include <map>
#include <sstream>
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

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

map<int, bool> check;

void dfs(Node *node) {
    cout << node->val << " ";
    check[node->val] = true;
    for (auto neighbor : node->neighbors) {
        if (!check[neighbor->val])
            dfs(neighbor);
    }
}

Node *cloneGraph(Node *node) {
    if (node == nullptr)
        return nullptr;
    queue<Node *> q;

    map<int, bool> visited;
    map<int, Node *> cloned;

    q.push(node);
    visited[node->val] = true;
    while (!q.empty()) {
        Node *u = q.front();
        q.pop();

        if (!cloned[u->val])
            cloned[u->val] = new Node(u->val);

        for (auto neighbor : u->neighbors) {
            if (!visited[neighbor->val]) {
                visited[neighbor->val] = true;
                q.push(neighbor);
            }

            if (!cloned[neighbor->val])
                cloned[neighbor->val] = new Node(neighbor->val);

            cloned[u->val]->neighbors.push_back(cloned[neighbor->val]);
        }
    }

    return cloned[node->val];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node *> nodes(n + 1);
        for (int i = 1; i <= n; i++)
            nodes[i] = new Node(i);

        FOR(i, 1, n) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            string word;
            while (ss >> word) {
                int neighbor = stoi(word);
                nodes[i]->neighbors.push_back(nodes[neighbor]);
            }
        }

        Node *root = cloneGraph(nodes[1]);

        check.clear();
        dfs(root);
        cout << endl;
    }

    return 0;
}
