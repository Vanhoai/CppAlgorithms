#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int c1 = 0, c2 = m - 1;
    int h1 = 0, h2 = n - 1;

    vector<int> v;
    while (c1 <= c2 && h1 <= h2) {
        // 1: traversal L -> R in top
        FOR(i, c1, c2) v.push_back(matrix[h1][i]);
        h1 += 1;

        // 2: traversal T -> B in right
        FOR(i, h1, h2) v.push_back(matrix[i][c2]);
        c2 -= 1;

        // 3: traversal R -> L in bottom
        FORD(i, c2, c1) v.push_back(matrix[h2][i]);
        h2 -= 1;

        // 4: traversal B -> T in left
        FORD(i, h2, h1) v.push_back(matrix[i][c1]);
        c1 += 1;
    }

    if (v.size() > n * m)
        v.resize(n * m);

    return v;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        FOR(i, 0, n - 1) FOR(k, 0, m - 1) cin >> matrix[i][k];

        vector<int> v = spiralOrder(matrix);
        FOR(i, 0, v.size() - 1) cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}
