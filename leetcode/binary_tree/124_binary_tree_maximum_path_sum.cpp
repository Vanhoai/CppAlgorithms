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

int backtracking(TreeNode *root, int &ans) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr) {
        ans = max(ans, root->val);
        return root->val;
    }

    int L = backtracking(root->left, ans);
    int R = backtracking(root->right, ans);

    if (L >= 0 && R >= 0)
        ans = max(ans, L + R + root->val);
    else if (L < 0 && R < 0)
        ans = max(ans, root->val);
    else if (L < 0)
        ans = max(ans, R + root->val);
    else
        ans = max(ans, L + root->val);

    return max(L, R) + root->val;
}

int maxPathSum(TreeNode *root) {
    if (root == nullptr)
        return 0;

    int ans = root->val;
    backtracking(root, ans);
    return ans;
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
        for (int i = 0; i < n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == nullptr)
                root = new TreeNode(u);

            addEdge(root, u, v, c);
        }

        cout << maxPathSum(root) << endl;
    }

    return 0;
}
