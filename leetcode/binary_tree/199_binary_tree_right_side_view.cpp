#include <iostream>
#include <map>
#include <queue>
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

vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr)
        return {};

    queue<pair<TreeNode *, int>> q;
    vector<int> rightSide;

    map<int, int> mp;

    q.push({root, 1});
    while (!q.empty()) {
        pair<TreeNode *, int> top = q.front();
        q.pop();
        mp[top.second] = top.first->val;

        if (top.first->left)
            q.push({top.first->left, top.second + 1});

        if (top.first->right)
            q.push({top.first->right, top.second + 1});
    }

    for (auto &[level, val] : mp)
        rightSide.push_back(val);

    return rightSide;
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

        vector<int> rights = rightSideView(root);
        for (int i = 0; i < rights.size(); i++)
            cout << rights[i] << " ";
        cout << endl;
    }

    return 0;
}
