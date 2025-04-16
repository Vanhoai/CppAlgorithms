#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i; k++) {
            swap(matrix[i][k], matrix[k][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n / 2; k++) {
            swap(matrix[i][k], matrix[i][n - k - 1]);
        }
    }
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
        vector<vector<int>> matrix(n, vector<int>(n));
        FOR(i, 0, n - 1) FOR(k, 0, n - 1) cin >> matrix[i][k];
        rotate(matrix);

        FOR(i, 0, n - 1) {
            FOR(k, 0, n - 1) cout << matrix[i][k] << " ";
            cout << endl;
        }
    }

    return 0;
}
