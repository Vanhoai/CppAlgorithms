#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Job & Profit
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 1000
 *      1 ≤ JobId ≤ 1000
 *      1 ≤ Deadline ≤ 1000
 *      1 ≤ Profit ≤ 1000.
 *
 * output: print the number job and profit
 *
 * @example
 *      input:
 *          2
 *          4
 *          1 4 20
 *          2 1 10
 *          3 1 40
 *          4 1 30
 *          5
 *          1 2 100
 *          2 1 19
 *          3 2 27
 *          4 1 25
 *          5 1 15
 *      output:
 *          2 60
 *          2 127
 */

struct Job {
    int id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) { return a.profit > b.profit; };

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        Job a[n];
        FOR(i, 0, n) cin >> a[i].id >> a[i].deadline >> a[i].profit;
        sort(a, a + n, cmp);

        bool used[n];
        int mark[n];
        ms(used, false);
        ms(mark, 0);

        int sum = 0;
        FOR(i, 0, n) INVERSE(j, a[i].deadline - 1, 0) {
            if (used[j] == false) {
                used[j] = true;
                mark[j] = i;
                sum += a[i].profit;
                break;
            }
        }

        int count = 0;
        FOR(i, 0, n) if (used[i]) count++;

        cout << count << " " << sum << endl;
    }

    return 0;
}
