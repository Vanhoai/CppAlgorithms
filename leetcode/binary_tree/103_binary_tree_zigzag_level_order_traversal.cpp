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

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr)
        return {};

    stack<TreeNode *> stack1, stack2;
    stack1.push(root);

    vector<vector<int>> ans;
    vector<int> level;
    while (!stack1.empty() || !stack2.empty()) {

        level.clear();
        while (!stack1.empty()) {
            TreeNode *u = stack1.top();
            stack1.pop();
            level.push_back(u->val);

            if (u->left != nullptr)
                stack2.push(u->left);

            if (u->right != nullptr)
                stack2.push(u->right);
        }

        if (!level.empty())
            ans.push_back(level);

        level.clear();
        while (!stack2.empty()) {
            TreeNode *u = stack2.top();
            stack2.pop();
            level.push_back(u->val);

            if (u->right != nullptr)
                stack1.push(u->right);

            if (u->left != nullptr)
                stack1.push(u->left);
        }

        if (!level.empty())
            ans.push_back(level);
    }

    if (!level.empty())
        ans.push_back(level);

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

        vector<vector<int>> ans = zigzagLevelOrder(root);
        for (const auto &level : ans) {
            for (int val : level)
                cout << val << " ";
            cout << endl;
        }
    }

    return 0;
}
