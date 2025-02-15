#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

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
    SETUP;

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