#include <iostream>
using namespace std;

/**
 * Swap digits
 *
 * input:
 *      T, K, S
 *      1 ≤ T ≤ 100
 *      1 ≤ K ≤ 10
 *      1 ≤ length(S) ≤ 7
 *
 * output: print the maximum number after swap k-th
 *
 * @example
 *      input:
 *          3
 *          4
 *          1234567
 *          3
 *          3435335
 *          2
 *          1034
 *      output:
 *          7654321
 *          5543333
 *          4301
 */

// not use recursive
void solve(string s, int k) {
    for (int i = 0; i < k; i++) {

        int imax = i;
        int mx = s[i] - '0';

        for (int k = i + 1; k < s.size(); k++) {
            if ((s[k] - '0') > mx) {
                mx = s[k] - '0';
                imax = k;
            }
        }

        if (imax != 1)
            swap(s[imax], s[i]);
    }

    cout << s << endl;
}

void backtracking(string s, int i, int k) {
    if (k == 0) {
        cout << s << endl;
        return;
    }

    int imax = i;
    int mx = s[i] - '0';

    for (int j = i + 1; j < s.size(); j++) {
        if ((s[j] - '0') > mx) {
            mx = s[j] - '0';
            imax = j;
        }
    }

    if (imax != 1)
        swap(s[imax], s[i]);

    backtracking(s, i + 1, k - 1);
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
        int k;
        string s;
        cin >> k;
        cin.ignore();
        cin >> s;

        backtracking(s, 0, k);
    }

    return 0;
}
