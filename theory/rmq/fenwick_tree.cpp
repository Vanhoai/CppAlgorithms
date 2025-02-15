#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 *
 * Fenwick Tree
 *
 * 11 3
 * 6 5 9 7 7 6 7 7 5 9 7
 * 1 9
 * 1 2
 * 0 8
 *
 * 59
 * 11
 * 54
 */

const int maxn = 1000005;
int a[maxn], bit[maxn], n, q;

/**
 * pos += pos & (-pos)
 *
 * pos = 3 -> 0011
 * -pos -> 1101
 *
 * -> pos & (-pos) => 0001 + 0011 = 0100 = 4
 */
void update(int pos, int value) {
    for (; pos <= n; pos += pos & (-pos))
        bit[pos] += value;
}

int query(int pos) {
    int sum = 0;
    for (; pos > 0; pos -= pos & (-pos))
        sum += bit[pos];

    return sum;
}

int main() {
    SETUP;

    cin >> n >> q;
    REP(i, 1, n) {
        cin >> a[i];
        update(i, a[i]);
    }

    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << query(R) - query(L - 1) << endl;
    }

    return 0;
}