#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Making Milk Tea
 *
 * input:
 *      1<=K<=N<=200000
 *      1<=Q<=200000
 *      1<=L,R<=200000
 *
 * output: print the number of cup enough standard serve for customer in range L -> R
 *
 * @example
 *      input: // N, K, Q
 *          5 3 4
 *          2 9
 *          5 8
 *          2 4
 *          2 4
 *          1 6
 *          3 4
 *          5 7
 *          5 8
 *          5 8
 *
 *      output:
 *          2
 *          2
 *          2
 *          2
 */

const int maxn = 200000;
int d[maxn + 1], f[maxn + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, q;
    cin >> n >> k >> q;
    ms(d, 0);

    while (n--) {
        int L, R;
        cin >> L >> R;
        d[L] += 1;
        d[R + 1] -= 1;
    }

    ms(f, 0);
    f[0] = d[0];
    FOR(i, 1, maxn + 1) f[i] = f[i - 1] + d[i];

    while (q--) {
        int L, R; cin >> L >> R;
        int count = 0;
        REP(i, L, R) if (f[i] >= k) count++;
        cout << count << endl;
    }
    
    return 0;
}
