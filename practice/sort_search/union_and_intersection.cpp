#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 *  Union & Intersection
 *
 * input:
 *      N, M, A[i], B[i]
 *      1 ≤ N, M ≤ 10^6
 *      -10^6 ≤ A[i], B[i] ≤ 10^6
 *
 * output: print array after sorted
 *
 * @example
 *      input:
 *          4 5
 *          1 2 3
 *          1 2 3 5 9
 *      output:
 *          1 2 3 5 9
 *          1 2 3
 */

void solve1() {

    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];

    vi intersection;
    set<int> unions;
    int i = 0, j = 0;
    while (i < n && j < m) {
        unions.insert(a[i]);
        unions.insert(b[j]);

        if (a[i] == b[j]) {
            intersection.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] > b[j])
            j++;
        else
            i++;
    }

    while (i < n)
        unions.insert(a[i++]);

    while (j < m)
        unions.insert(b[j++]);

    for (auto it : unions)
        cout << it << " ";

    cout << endl;

    for (auto it : intersection)
        cout << it << " ";
}

int main() {
    SETUP;
    int n, m;
    cin >> n >> m;

    mii mp;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        mp[x]++;
    }

    FOR(i, 0, m) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (auto it : mp)
        cout << it.first << " ";
    cout << endl;

    for (auto it : mp) {
        if (it.second >= 2)
            cout << it.first << " ";
    }
    return 0;
}