#include <ios>
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

TreeNode *build(int L, int R, vector<int> nums) {
    if (L > R)
        return nullptr;

    int M = (L + R) >> 1;
    TreeNode *root = new TreeNode(nums[M]);
    root->left = build(L, M - 1, nums);
    root->right = build(M + 1, R, nums);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty())
        return nullptr;
    int L = 0, R = nums.size() - 1;
    return build(L, R, nums);
}

void inorder(TreeNode *root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        TreeNode *root = sortedArrayToBST(nums);
        inorder(root);
        cout << endl;
    }

    return 0;
}
