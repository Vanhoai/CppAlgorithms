#include <iostream>
using namespace std;

int n, A[100][100];
string path;

void backtracking(int i, int j) {
    if (i == n && j == n)
        cout << path << endl;

    if (i + 1 <= n && A[i + 1][j] == 1) {
        // move down
        path += "D";
        A[i + 1][j] = 0;
        backtracking(i + 1, j);

        // backtrack
        path.pop_back();
        A[i + 1][j] = 1;
    }

    if (j + 1 <= n && A[i][j + 1] == 1) {
        // move right
        path += "R";
        A[i][j + 1] = 0;
        backtracking(i, j + 1);

        // backtrack
        path.pop_back();
        A[i][j + 1] = 1;
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
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> A[i][j];
            }
        }

        backtracking(1, 1);
        cout << endl;
    }

    return 0;
}
