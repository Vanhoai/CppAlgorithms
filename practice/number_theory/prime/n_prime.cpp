#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * N Prime first
 *
 * input:
 *      N: the number of number is prime
 *
 * output: print n numbers that are prime first from 2
 *
 * @example
 *      input: N = 5
 *      output: 2 3 5 7 11
 */

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int main() {
    SETUP;

    int N;
    cin >> N;

    int count = 0;
    int i = 2;
    while (count < N) {
        if (is_prime(i)) {
            count++;
            cout << i << " ";
        }

        i++;
    }

    return 0;
}