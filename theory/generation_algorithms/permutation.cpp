#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int n, ok, X[100];

void init() {
    for (int i = 1; i <= n; i++)
        X[i] = i;
}

void gen() {
    int i = n - 1;
    while (i >= 1 && X[i] > X[i + 1])
        i--;

    if (i == 0)
        ok = 0;
    else {
        // X[i] < X[i + 1]
        // find min element and > X[i]
        int j = n;
        while (X[i] > X[j])
            j--;

        swap(X[i], X[j]);
        // sort (i + 1, n) ascending
        // sort(X + i + 1, X + n + 1);

        // reverse (i + 1, n)
        reverse(X + i + 1, X + n + 1);
    }
}

void generate() {
    cin >> n;
    init();
    do {
        for (int i = 1; i <= n; i++)
            cout << X[i] << " ";
        cout << endl;

    } while (next_permutation(X + 1, X + n + 1));
}

int main() {
    SETUP;

    cin >> n;
    init();

    ok = 1;
    while (ok) {
        for (int i = 1; i <= n; i++) {
            cout << X[i] << " ";
        }

        cout << endl;
        gen();
    }

    return 0;
}