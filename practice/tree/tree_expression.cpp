#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

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
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}