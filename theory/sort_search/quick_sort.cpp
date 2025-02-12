#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

// use hoare
int partition(int a[], int L, int R) {
    int m = (L + R) >> 1;
    int p = a[m];

    int i = L, j = R;
    while (i < j) {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;

        if (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    return i;
}

void quick_sort(int a[], int L, int R) {
    if (L >= R)
        return;

    int pivot = partition(a, L, R);
    quick_sort(a, L, pivot - 1);
    quick_sort(a, pivot + 1, R);
}

int main() {
    SETUP;

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    quick_sort(a, 0, n - 1);

    FOR(i, 0, n) cout << a[i] << " ";

    return 0;
}