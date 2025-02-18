#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sphenic Number
 * A positive integer N is called a Sphenic number if N can be uniquely
 * expressed as the product of three different numbers. For example, N = 30 is a
 * Sphenic number because 30 = 2×3×5; N = 60 is not a Sphenic number because 60
 * = 2×2×3×5. Given a natural number N, your task is to check whether N is a
 * Sphenic number or not?
 *
 * input:
 *      T: 1 ≤ T ≤ 100
 *      N: 1 ≤ N ≤ 10^5
 *
 * output: YES/NO
 *
 * @example
 *      input: 30
 *      output: YES
 */

int solve(int n) {
    map<int, int> mp;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }

    if (n > 1)
        mp[n]++;

    if (mp.size() != 3)
        return 0;

    for (auto it : mp) {
        if (it.second > 1)
            return 0;
    }

    return 1;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;
        if (solve(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}