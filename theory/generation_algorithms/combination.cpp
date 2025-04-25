#include <iostream>
using namespace std;

int n, k, ok, X[100];

void init() {
    for (int i = 1; i <= k; i++)
        X[i] = i;
}

void generate() {
    int i = k;
    while (i >= 1 && X[i] == n - k + i)
        i--;

    if (i == 0)
        ok = 0;
    else {
        X[i]++;
        for (int j = i + 1; j <= k; j++)
            X[j] = X[j - 1] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> k;
    init();

    ok = 1;
    while (ok) {
        for (int i = 1; i <= k; i++) {
            cout << X[i] << " ";
        }

        cout << endl;

        generate();
    }

    return 0;
}
