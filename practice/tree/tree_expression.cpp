#include <iostream>
using namespace std;

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
 * 2
 * ab+ef*g*- -> a+b-e*f*g
 * wlrb+-* -> w*l-r+b
 */

struct Node {
    int value;
    Node *L, *R;

    Node(int value) {
        this->value = value;
        L = R = nullptr;
    }
};

bool check(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

void inOrder(Node *root) {
    if (root == nullptr)
        return;
    inOrder(root->L);
    cout << (char) root->value;
    inOrder(root->R);
}

void preOrder(Node *root) {
    if (root == nullptr)
        return;

    cout << (char) root->value;
    inOrder(root->L);
    inOrder(root->R);
}

void posOrder(Node *root) {
    if (root == nullptr)
        return;
    inOrder(root->L);
    inOrder(root->R);
    cout << (char) root->value;
}

void solve(string s) {
    stack<Node *> st;
    Node *root;

    FOR(i, 0, sz(s)) {
        if (!check(s[i]))
            st.push(new Node(s[i]));
        else {
            Node *tmp = new Node(s[i]);

            Node *o1 = st.top();
            st.pop();
            Node *o2 = st.top();
            st.pop();

            tmp->L = o2;
            tmp->R = o1;
            st.push(tmp);
        }
    }

    root = st.top();
    inOrder(root);
    cout << endl;
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
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}
