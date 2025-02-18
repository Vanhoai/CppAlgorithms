#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Special Character
 *
 * input:
 *      T < 10
 *      1 ≤ N ≤ 10^18
 *
 * output: print character k-th
 *
 * @example
 *      input:
 *          1
 *          COW 8
 *      output:
 *          C
 *          COW -> COWWCO -> COWWCOOCOWWC
 */

string s;
ll n, length;

char search(ll n, ll k) {
    if (n <= s.size())
        return s[n - 1];
    if (n <= k / 2)
        return search(n, k / 2);
    else {
        ll tmp = n - k / 2;
        if (tmp == 1)
            return search(k / 2, k / 2);
        else
            return search(tmp - 1, k / 2);
    }
}

void solve() {
    cin >> s >> n;

    length = s.size();
    while (length < n)
        length <<= 1;

    cout << search(n, length);
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}