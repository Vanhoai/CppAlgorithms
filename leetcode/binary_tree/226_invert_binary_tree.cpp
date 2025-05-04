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

TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
        return nullptr;

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);

    root->left = right;
    root->right = left;
    return root;
}

void inorderTraversal(TreeNode *root) {
    if (!root)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
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

        inorderTraversal(root);
        cout << endl;

        TreeNode *invertedRoot = invertTree(root);
        inorderTraversal(invertedRoot);
        cout << endl;
    }

    return 0;
}
