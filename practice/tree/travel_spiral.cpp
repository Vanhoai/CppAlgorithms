#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

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

void spiralOrder(Node *root) {
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty() || !st2.empty()) {
        while (!st1.empty()) {
            Node *tmp = st1.top();
            st1.pop();
            cout << tmp->value << " ";

            if (tmp->R != nullptr)
                st2.push(tmp->R);

            if (tmp->L != nullptr)
                st2.push(tmp->L);
        }

        while (!st2.empty()) {
            Node *tmp = st2.top();
            st2.pop();
            cout << tmp->value << " ";

            if (tmp->L != nullptr)
                st1.push(tmp->L);

            if (tmp->R != nullptr)
                st1.push(tmp->R);
        }
    }

    cout << endl;
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

        spiralOrder(root);
    }

    return 0;
}