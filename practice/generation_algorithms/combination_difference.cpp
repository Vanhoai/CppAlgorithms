#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
8 3
1 2 2 2 1 3 2 5

output:
1 2 3
1 2 5
2 3 5

*/

int n, k, ok, X[11];

void init() {
    for (int i = 1; i <= k; i++)
        X[i] = i;
}

void gen() {
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
    SETUP;

    set<int> se;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        se.insert(x);
    }

    n = se.size();
    init();

    ok = 1;

    vector<int> v(se.begin(), se.end());
    while (ok) {
        for (int i = 1; i <= k; i++)
            cout << v[X[i] - 1] << " ";

        cout << endl;
        gen();
    }

    return 0;
}