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

vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    vector<double> averages;
    while (!q.empty()) {

        int n = q.size();
        double sum = 0;

        for (int i = 0; i < n; i++) {
            TreeNode *node = q.front();
            q.pop();
            sum += node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        averages.push_back(sum / n);
    }

    return averages;
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

        vector<double> average = averageOfLevels(root);
        for (double it : average)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}
