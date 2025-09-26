//
// File        : difference_array.cpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * @brief Difference Array
 * @details Given an array of n integers, we want to perform multiple range
 * updates, where each update adds a certain value to all elements between two
 * given indices (L, R) (0-based).
 *
 * We can use a difference array to efficiently handle these range updates. The
 * difference array is constructed such that each element at index i contains
 * the difference between the element at index i and the element at index i-1 in
 * the original array. This allows us to perform range updates in O(1) time.
 * After all updates, we can reconstruct the original array by taking the
 * prefix sum of the difference array.
 *
 * Input:
 * 7 3
 * 8 5 8 9 7 6 9
 * 0 5 0
 * 0 5 0
 * 1 5 1
 *
 * Output:
 * 8 6 9 10 8 7 9
 */

#include <core/core.hpp>
#include <iostream>

using namespace std;
using namespace core;

int main() {
    core::io();

    int n, q;
    cin >> n >> q;

    vi a(n);
    FOR(i, 0, n - 1) cin >> a[i];

    vi d(n + 1);
    d[0] = a[0];
    FOR(i, 1, n - 1) d[i] = a[i] - a[i - 1];

    while (q--) {
        int L, R, K;
        cin >> L >> R >> K;
        d[L] += K;
        if (R + 1 < n)
            d[R + 1] -= K;
    }

    FOR(i, 1, n - 1) d[i] += d[i - 1];
    FOR(i, 0, n - 1) cout << d[i] << " ";

    return 0;
}
