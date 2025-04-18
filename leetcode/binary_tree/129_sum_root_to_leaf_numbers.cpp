#include <iostream>
#include <typeinfo>
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

void makeEdge(TreeNode *u, int v, char c) {
    if (c == 'L')
        u->left = new TreeNode(v);
    else
        u->right = new TreeNode(v);
}

void addEdge(TreeNode *root, int u, int v, char c) {
    if (root == nullptr)
        return;

    if (root->val == u) {
        makeEdge(root, v, c);
        return;
    }

    addEdge(root->left, u, v, c);
    addEdge(root->right, u, v, c);
}

void inorder(TreeNode *root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

vector<string> results;
int path = 0;
int sum = 0;

void backtracking(TreeNode *root) {
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        path = path * 10 + root->val;
        sum += path;
        path = path / 10;
        return;
    }

    path = path * 10 + root->val;
    backtracking(root->left);
    backtracking(root->right);
    path = path / 10;
}

int sumNumbers(TreeNode *root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return root->val;

    backtracking(root);
    return sum;
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

        results.clear();
        path = "";
        cout << sumNumbers(root) << endl;
    }

    return 0;
}
