#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
1
3 10
2 4 3
1 3 6
4 2 4

output:
2
1 3 2
3 2 1

 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1][n + 1];
        int g[n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
            g[i] = i;

        vector<string> v;
        do {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += a[i][g[i]];
            }

            if (sum == k) {
                string res = "";
                for (int i = 1; i <= n; i++) {
                    res += to_string(g[i]);
                    res += " ";
                }

                v.push_back(res);
            }
        } while (next_permutation(g + 1, g + n + 1));

        cout << v.size() << endl;
        for (auto it : v)
            cout << it << endl;

        cout << endl;
    }

    return 0;
}