#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * sort() -> intro sort (heap sort and quick sort)
 * stable_sort() -> sort but with stability (merge sort)
 */

void theory() {
    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    stable_sort(a, a + n, greater<int>());

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

bool cmp(pi a, pi b) {
    if (a.S == b.S)
        return a.F > b.F;
    return a.S > b.S;
}

void sort_frequency(int a[], int n) {
    map<int, int> mp;
    FOR(i, 0, n) mp[a[i]]++;

    vii v;
    for (int i = 0; i < n; i++)
        v.PB(MP(a[i], mp[a[i]]));

    sort(v.begin(), v.end(), cmp);
    FOR(i, 0, v.size()) cout << v[i].F << " ";

    sort(a, a + n, [](int a, int b) -> bool { return a > b; });
    FOR(i, 0, n) cout << a[i] << " ";

    cout << endl;
}

int main() {
    SETUP;

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    sort_frequency(a, n);
    return 0;
}