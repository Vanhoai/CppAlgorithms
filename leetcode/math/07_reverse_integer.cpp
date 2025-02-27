#include "bits/stdc++.h"
using namespace std;

/**
 * Leetcode 7: https://leetcode.com/problems/reverse-integer/
 *
 * input:
 *      4
 *      123
 *      -123
 *      120
 *      1534236469
 *
 * ouput:
 *      321
 *      -321
 *      21
 *      0
 */

int reverse(int x) {
    bool negative = x < 0;
    long long n = abs(1LL * x);

    long long res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }

    if (negative) {
        if (-res < INT_MIN)
            return 0;
        return -res;
    } else {
        if (res > INT_MAX)
            return 0;
        return res;
    }
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
        int n;
        cin >> n;
        cout << reverse(n) << endl;
    }

    return 0;
}
