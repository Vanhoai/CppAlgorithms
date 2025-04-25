#include <iostream>
using namespace std;

/**
 * Smith Number
 * Given a natural number N. Your task is to check whether N is a Smith number
 * or not. A number is called a Smith number if N is not prime and the sum of
 * the digits of N is equal to the sum of the digits of the prime divisors of N.
 * For example, N = 666 has prime divisors 2, 3, 3, 37 whose sum of digits
 * is 18.
 *
 * input:
 *      T: 1 ≤ T ≤ 100
 *      N: 1 ≤ N ≤ 10^5
 *
 * output: YES/NO
 *
 * @example
 *      input: 666
 *      output: YES
 */

int sum_digit(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int sum_factors(int n) {
    int sum = 0;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            sum += sum_digit(i);
            n /= i;
        }
    }

    if (n > 1) {
        sum += sum_digit(n);
    }

    return sum;
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

        if (sum_digit(N) == sum_factors(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
