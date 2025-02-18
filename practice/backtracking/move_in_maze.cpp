#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/*
input:
2
4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
5
1 0 0 0 0
1 1 1 1 1
1 1 0 0 1
0 1 1 1 1
0 0 0 1 1

1 ≤ T ≤10
2 ≤ N ≤ 10
0 ≤ A[i][j] ≤ 1

output:
DRDDRR
DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD
DRRRRDDD
*/

int n, ok, A[100][100];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
}

void backtracking(int i, int j, string s) {
    if (i == n && j == n) {
        ok = 1;
        cout << s << " ";
    }

    if (i + 1 <= n && A[i + 1][j] == 1) {
        backtracking(i + 1, j, s + "D");
    }

    if (j + 1 <= n && A[i][j + 1] == 1) {
        backtracking(i, j + 1, s + "R");
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        ok = 0;
        backtracking(1, 1, "");

        if (!ok)
            cout << -1;

        cout << endl;
    }

    return 0;
}