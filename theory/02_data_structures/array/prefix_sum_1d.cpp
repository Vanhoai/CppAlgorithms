//
// File        : prefix_sum_1d.cpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * Prefix Sum 1D
 * Given an array of n integers, we want to answer multiple queries of the sum
 * of elements between two given indices (L, R) (0-based).
 *
 * We can preprocess the array to create a prefix sum array, where each element
 * at index i contains the sum of elements from the start of the array to index
 * i. This allows us to answer each query in O(1) time after an O(n)
 * preprocessing step.
 *
 * Input:
 * 5
 * 4 2 1 3 5
 * 3
 * 0 2
 * 1 3
 * 2 4
 *
 * Output:
 * 7
 * 6
 * 9
 */

#include <core/core.hpp>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    core::io();

    int n;
    cin >> n;
    vector<int> v(n), f(n, 0);
    FOR(i, 0, n - 1) cin >> v[i];

    f[0] = v[0];
    FOR(i, 1, n - 1) f[i] = f[i - 1] + v[i];

    int TC;
    cin >> TC;
    while (TC--) {
        int L, R;
        cin >> L >> R;
        if (L == 0)
            cout << f[R] << endl;
        else
            cout << f[R] - f[L - 1] << endl;
    }

    return 0;
}
