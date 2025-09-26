#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void makeEdge(TreeNode *&node, int v, char c) {
    if (c == 'L')
        node->left = new TreeNode(v);
    else
        node->right = new TreeNode(v);
}

void addEdge(TreeNode *&root, int u, int v, char c) {
    if (root == nullptr)
        return;

    if (root->val == u) {
        makeEdge(root, v, c);
        return;
    }

    addEdge(root->left, u, v, c);
    addEdge(root->right, u, v, c);
}

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr || q == nullptr)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
        int n, m;
        cin >> n >> m;

        TreeNode *p = nullptr;
        for (int i = 0; i < n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (p == nullptr)
                p = new TreeNode(u);

            addEdge(p, u, v, c);
        }

        TreeNode *q = nullptr;
        for (int i = 0; i < m; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (q == nullptr)
                q = new TreeNode(u);

            addEdge(q, u, v, c);
        }

        cout << (isSameTree(p, q) ? "YES" : "NO") << endl;
    }

    return 0;
}
