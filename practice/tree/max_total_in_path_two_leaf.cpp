#include <iostream>
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

/**
 * 1
 * 12
 * -15 5 L
 * -15 6 R
 * 5 -8 L
 * 5 1 R
 * -8 2 L
 * -8 -3 R
 * 6 3 L
 * 6 9 R
 * 9 0 R
 * 0 4 L
 * 0 -1 R
 * -1 10 L
 *
 * 27
 */

struct Node {
    int value;
    Node *L, *R;

    Node(int value) {
        this->value = value;
        L = R = nullptr;
    }
};

void makeNode(Node *root, int u, int v, char c) {
    if (c == 'L') {
        root->L = new Node(v);
    } else
        root->R = new Node(v);
}

void insertNode(Node *root, int u, int v, char c) {
    if (root == nullptr)
        return;

    if (root->value == u)
        makeNode(root, u, v, c);

    insertNode(root->R, u, v, c);
    insertNode(root->L, u, v, c);
}

int maxSum(Node *root, int &ans) {
    if (root == nullptr)
        return 0;
    if (root->L == nullptr && root->R == nullptr)
        return root->value;

    int l = maxSum(root->L, ans);
    int r = maxSum(root->R, ans);

    if (root->L != nullptr && root->R != nullptr) {
        ans = max(ans, l + r + root->value);
        return max(l, r) + root->value;
    }

    if (root->L == nullptr)
        return r + root->value;

    if (root->R == nullptr)
        return l + root->value;

    return 0;
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
        Node *root = nullptr;

        FOR(i, 0, n) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == nullptr) {
                root = new Node(u);
                makeNode(root, u, v, c);
            } else {
                insertNode(root, u, v, c);
            }
        }

        int ans = -1e9;
        maxSum(root, ans);

        cout << ans << endl;
    }

    return 0;
}
