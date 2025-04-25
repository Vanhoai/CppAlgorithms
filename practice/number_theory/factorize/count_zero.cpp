#include <iostream>
using namespace std;

/**
 * Count Zero
 *
 * input:
 *      T: 1 ≤ T ≤ 100
 *      N: 1 ≤ N ≤ 10^6
 *
 * output: Print the number of consecutive zeros from the end of n!.
 *
 * @example
 *      input: 20
 *      output: 4 -> (20! -> 2432902008176640000 has 4 zeros)
 */

int solve(int n) {

    int count = 0;
    for (int i = n; i >= 1; i--) {
        int k = i;

        for (int j = 2; j * j <= k; j++) {
            while (k % j == 0) {
                k /= j;
                if (j == 5)
                    count++;
            }
        }

        if (k == 5)
            count++;
    }

    return count;
}

int degree(int n, int p) {
    int count = 0;
    for (int i = p; i <= n; i *= p) {
        count += n / i;
    }

    return count;
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
        int N;
        cin >> N;
        cout << degree(N, 5) << endl;
    }
    return 0;
}
