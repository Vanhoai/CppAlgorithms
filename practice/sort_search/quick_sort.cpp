#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 * Quicksort
 *
 * input:
 *      T, N, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^5
 *
 * output: print sorted array
 *
 * @example
 *      input:
 *          8
 *          8 7 2 1 5 3 6 4
 *      output:
 *          2 1 3 4 5 8 6 7
 */

// quicksort with lomuto partition
void qs_lomuto(int a[], int l, int r) {
    if (l < r) {
        int i = l - 1, x = a[r];
        for (int j = l; j < r; j++) {
            if (a[j] < x) {
                ++i;
                swap(a[i], a[j]);
            }
        }
        ++i;
        swap(a[i], a[r]);

        qs_lomuto(a, l, i - 1);
        qs_lomuto(a, i + 1, r);
    }
}

// quicksort with hoare partition, pivot is the last element of segment
void qs_hoare(int a[], int l, int r) {
    int i = l, j = r, x = a[r];
    while (i <= j) {
        while (a[i] < x)
            ++i;
        while (a[j] > x)
            --j;

        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (i < r)
        qs_hoare(a, i, r);
    if (l < j)
        qs_hoare(a, l, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    qs_lomuto(a, 0, n - 1);
    qs_hoare(a, 0, n - 1);

    FOR(i, 0, n) cout << a[i] << " ";

    return 0;
}
