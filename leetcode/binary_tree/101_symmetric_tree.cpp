#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void makeEdge(TreeNode *&root, int v, char c) {
    if (c == 'L')
        root->left = new TreeNode(v);
    else
        root->right = new TreeNode(v);
}

void addEdge(TreeNode *&root, int u, int v, char c) {
    if (!root)
        return;

    if (root->val == u) {
        makeEdge(root, v, c);
        return;
    }

    addEdge(root->left, u, v, c);
    addEdge(root->right, u, v, c);
}

bool isMirror(TreeNode *left, TreeNode *right) {
    if (!left && !right)
        return true;

    if (!left || !right)
        return false;

    bool L = isMirror(left->left, right->right);
    bool R = isMirror(left->right, right->left);
    return (left->val == right->val) && L && R;
}

bool isSymmetric(TreeNode *root) {
    if (!root)
        return true;

    return isMirror(root->left, root->right);
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
        TreeNode *root = nullptr;
        for (int i = 0; i < n; ++i) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == nullptr)
                root = new TreeNode(u);

            addEdge(root, u, v, c);
        }

        cout << (isSymmetric(root) ? "YES" : "NO") << endl;
    }

    return 0;
}
