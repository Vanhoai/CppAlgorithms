#include <iostream>
using namespace std;

int n, A[100][100];
string path;

// D, L, R, U
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char d[4] = {'D', 'L', 'R', 'U'};

void backtracking(int i, int j) {
    if (i == n && j == n)
        cout << path << endl;

    for (int k = 0; k < 4; k++) {
        int ix = i + dx[k];
        int jy = j + dy[k];

        if (ix >= 1 && ix <= n && jy >= 1 && jy <= n && A[ix][jy] == 1) {
            A[i][j] = 0;
            path += d[k];

            backtracking(ix, jy);

            path.pop_back();
            A[i][j] = 1;
        }
    }
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
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
        input();

        A[1][1] = 0;
        backtracking(1, 1);
        cout << endl;
    }

    return 0;
}
