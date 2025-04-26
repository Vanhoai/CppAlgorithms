#include <iostream>
using namespace std;

void generate(vector<int> &X, int n, bool &end) {
    int i = n - 1;
    while (i >= 1 && X[i] > X[i + 1])
        i--;

    if (i == 0) {
        end = true;
    } else {
        int j = n;
        while (X[i] > X[j])
            j--;

        swap(X[i], X[j]);
        reverse(X.begin() + i + 1, X.end());
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> perms;

    int n = nums.size();
    vector<int> X(n + 1);

    for (int i = 1; i <= n; i++)
        X[i] = i;

    bool end = false;
    do {
        if (!end) {
            vector<int> v(nums.size());
            for (int i = 1; i <= n; i++)
                v[i - 1] = nums[X[i] - 1];

            perms.push_back(v);
        }
        generate(X, n, end);
    } while (!end);

    return perms;
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

        vector<vector<int>> perms = permute(nums);
        for (int i = 0; i < perms.size(); i++) {
            for (int j = 0; j < perms[i].size(); j++)
                cout << perms[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
