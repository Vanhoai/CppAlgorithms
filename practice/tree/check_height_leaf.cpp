#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * 2
 * 2
 * 1 2 R 1 3 L
 * 4
 * 10 20 L 10 30 R 20 40 L 20 60 R
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

    return check(root->L, level + 1, h) && check(root->R, level + 1, h);
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

        int h = height(root);
        if (check(root, 1, h))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}