#include <iostream>
using namespace std;

/**
 * Powers and factorials.
 * Given a natural number N and a prime number P. Your task is to find the
 * largest number x so that N! is divisible by px . For example, with N=7, p=3,
 * then x=2 is the largest number so that 7! is divisible by 3^2
 *
 * input:
 *      T: 1 ≤ T ≤ 100
 *      N: 1 ≤ N ≤ 10^5
 *      P: 2 ≤ p ≤ 5000
 *
 * output: print count of prime factors of a number n
 *
 * @example
 *      input: 62 7
 *      output: 9
 */

int solve(int N, int p) {
    int count = 0;
    for (int i = N; i >= 1; i--) {
        int k = i;
        for (int j = 2; j * j <= k; j++) {
            while (k % j == 0) {
                k /= j;
                if (j == p)
                    count++;
            }
        }

        if (k == p)
            count++;
    }

    return count;
}

int degree(int N, int p) {
    int ans = 0;
    for (int i = p; i <= N; i *= p) {
        ans += N / i;
    }

    return ans;
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
        int N, p;
        cin >> N >> p;

        cout << degree(N, p) << endl;
    }

    return 0;
}
