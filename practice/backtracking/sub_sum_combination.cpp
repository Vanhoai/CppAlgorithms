#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, k, s, res, X[100];

void backtracking(int i) {
    for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
        X[i] = j;
        if (i == k) {
            int sum = 0;
            for (int b = 1; b <= k; b++)
                sum += X[b];

            if (sum == s)
                res++;
        } else {
            backtracking(i + 1);
        }
    }
}

void back(int sum, int cnt, int pos) {
    if (sum == s && cnt == k)
        res++;
    else {
        for (int j = pos; j <= n; j++) {
            if (sum + j <= s && cnt + 1 <= k)
                back(sum + j, cnt + 1, j + 1);
        }
    }
}

int main() {
    SETUP;

    while (true) {
        cin >> n >> k >> s;
        if (n + k + s == 0)
            break;
        res = 0;
        memset(X, 0, sizeof(X));
        back(0, 0, 1);

        cout << res << endl;
    }

    return 0;
}