#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
input
3
5 3
1 3 5
5 3
1 4 5
6 4
3 4 5 6

output:
1
2
4

 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        int a[k];
        set<int> se;
        FOR(i, 0, k) {
            int x;
            cin >> x;
            a[i] = x;
            se.insert(x);
        };

        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1)
            i--;

        if (i == -1)
            cout << k;
        else {
            a[i]++;
            for (int j = i + 1; j < k; j++)
                a[j] = a[j - 1] + 1;

            // compare two arrays
            for (int i = 0; i < k; i++) {
                se.erase(a[i]);
            }

            cout << se.size();
        }

        cout << endl;
    }

    return 0;
}