#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * 2
 * 2
 * 1 2 L 1 3 R
 * 2
 * 1 2 L 1 3 R
 * 2
 * 1 2 L 1 3 R
 * 1 2 L 1 2 R
 *
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

bool identical(Node *node1, Node *node2) {
    if (node1 == nullptr && node2 == nullptr)
        return true;
    if (node1 != nullptr && node2 != nullptr)
        return (node1->value == node2->value) &&
               identical(node1->L, node2->L) && identical(node1->R, node2->R);

    return false;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        Node *root1 = nullptr;
        Node *root2 = nullptr;

        FOR(i, 0, n) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root1 == nullptr) {
                root1 = new Node(u);
                makeNode(root1, u, v, c);
            } else {
                insertNode(root1, u, v, c);
            }
        }

        cin >> n;
        FOR(i, 0, n) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root2 == nullptr) {
                root2 = new Node(u);
                makeNode(root2, u, v, c);
            } else {
                insertNode(root2, u, v, c);
            }
        }

        if (identical(root1, root2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}