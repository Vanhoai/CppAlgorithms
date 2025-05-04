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

bool backtracking(TreeNode *root, int &sum, int target) {
    if (!root)
        return false;

    if (!root->left && !root->right && sum + root->val == target)
        return true;

    sum += root->val;
    bool left = backtracking(root->left, sum, target);
    bool right = backtracking(root->right, sum, target);
    sum -= root->val;

    return left || right;
}

bool hasPathSum(TreeNode *root, int targetSum) {
    int sum = 0;
    return backtracking(root, sum, targetSum);
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
        int n, target;
        cin >> n >> target;
        TreeNode *root = nullptr;
        for (int i = 0; i < n; ++i) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == nullptr)
                root = new TreeNode(u);

            addEdge(root, u, v, c);
        }

        cout << (hasPathSum(root, target) ? "YES" : "NO") << endl;
    }

    return 0;
}
