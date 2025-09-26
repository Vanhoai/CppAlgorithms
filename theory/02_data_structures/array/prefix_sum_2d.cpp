//
// File        : prefix_sum_2d.cpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * Prefix Sum 2D
 * Given a 2D matrix of integers, we want to answer multiple queries of the sum
 * of elements within a submatrix defined by its top-left and bottom-right
 * corners.
 *
 * We can preprocess the matrix to create a 2D prefix sum array, where each
 * element at position (i, j) contains the sum of elements from the top-left
 * corner (0, 0) to (i, j). This allows us to answer each query in O(1) time
 * after an O(m * n) preprocessing step, where m and n are the dimensions of
 * the matrix.
 *
 * Input:
 * 3 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 2
 * 0 0 1 1
 * 1 1 2 2
 *
 * Output:
 * 12
 * 28
 */

#include <core/core.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace core;

int main() {
    core::io();

    int n, m;
    cin >> n >> m;
    vvi a(n + 1, vi(m + 1)), f(n + 1, vi(m + 1));
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    FOR(i, 1, n) FOR(j, 1, m) {
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
    }

    int q;
    cin >> q;
    while (q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;

        // Convert to 1-based indexing
        i1++, j1++, i2++, j2++;

        cout << f[i2][j2] - f[i1 - 1][j2] - f[i2][j1 - 1] + f[i1 - 1][j1 - 1]
             << endl;
    }

    return 0;
}
