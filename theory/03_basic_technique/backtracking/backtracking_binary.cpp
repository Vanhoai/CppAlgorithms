#include <iostream>
using namespace std;

int n, X[100];

void out() {
    for (int i = 1; i <= n; i++)
        cout << X[i];
}

void backtracking(int i) {
    for (int j = 0; j <= 1; j++) {
        X[i] = j;
        if (i == n) {
            out();
            cout << endl;
        } else
            backtracking(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    backtracking(1);

    return 0;
}
