#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/*
input:
1
5
1 2 3 4 5

output:
[1 2 3 4 5]
[3 5 7 9]
[8 12 16]
[20 28]
[48]

*/

int n, X[100];

void print(int m) {
    cout << "[";
    for (int k = 1; k <= m; k++) {
        cout << X[k];
        if (k != m)
            cout << " ";
    }
    cout << "]" << endl;
}

void backtracking(int i) {
    if (i == 0)
        return;

    print(i);

    for (int k = 1; k <= i; k++)
        X[k] += X[k + 1];

    backtracking(i - 1);
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> X[i];

        backtracking(n);
    }

    return 0;
}