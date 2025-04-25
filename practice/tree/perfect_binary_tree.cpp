#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 * 3
 * 6
 * 10 20 L 10 30 R 20 40 L 20 50 R 30 60 L 30 70 R
 * 2
 * 18 15 L 18 30 R
 * 5
 * 1 2 L 2 4 R 1 3 R 3 5 L 3 6 R
 *
 * YES
 * YES
 * NO
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

int height(Node *root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->L), height(root->R));
}

bool check(Node *root, int level, int h) {
    if (root == nullptr)
        return true;
    if (root->L == nullptr && root->R == nullptr && level < h)
        return false;

    return check(root->L, level + 1, h) && check(root->R, level + 2, h);
}

bool check2(Node *root) {
    if (root == nullptr)
        return true;
    if ((root->R == nullptr && root->L != nullptr) ||
        (root->R != nullptr && root->L == nullptr))
        return false;

    return check2(root->L) && check2(root->R);
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

        int h = height(root);
        if (check(root, 1, h) && check2(root))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
