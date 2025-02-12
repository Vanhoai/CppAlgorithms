#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * lower_bound(): return iterator to first element greater than or equal to x
 * upper_bound(): return iterator to first element greater than x
 * equal_range(): return pair of iterators to first and last element equal to x
 * distance(): return the number of elements between two iterators
 * binary_search(): return true if x is found, false otherwise
 */

int binary_search_own(int a[], int n, int x) {
    int L = 0, R = n - 1;
    while (L <= R) {
        int M = (L + R) >> 1;
        if (a[M] == x) {
            return 1;
        } else if (a[M] < x)
            L = M + 1;
        else
            R = M - 1;
    }

    return -1;
}

void theory_binary_search() {
    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];
    sort(a, a + n);

    int x = 2;
    if (binary_search(a, a + n, x))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
}

void theory_search() {
    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];
    sort(a, a + n);

    auto x = lower_bound(a, a + n, 5) - a;
    cout << "Lower bound -> index: " << x << " value: " << a[x] << endl;

    x = upper_bound(a, a + n, 5) - a;
    cout << "Upper bound -> index: " << x << " value: " << a[x] << endl;

    // Equal range way 1 (upper_bound - lower_bound)
    auto u = upper_bound(a, a + n, 5) - a;
    auto l = lower_bound(a, a + n, 5) - a;
    cout << "Equal range -> the number of elements equal to 5 is " << u - l
         << endl;

    // Equal range way 2 (equal_range)
    auto p = equal_range(a, a + n, 5);
    cout << "Equal range -> the number of elements equal to 5 is "
         << p.second - p.first << endl;
}

void set_search() {
    multiset<int> se;
    for (int i = 1; i <= 20; i++) {
        int r = rand() % 20;
        se.insert(r);
    }

    for (auto it : se)
        cout << it << " ";
    cout << endl;

    int x = 5;
    auto a = se.upper_bound(x);
    cout << "Lower bound -> index: " << *a << endl;
    cout << "Distance from begin: " << distance(se.begin(), a) << endl;

    se.erase(a);
    for (auto it : se)
        cout << it << " ";
    cout << endl;
}

int main() {
    SETUP;
    set_search();

    return 0;
}