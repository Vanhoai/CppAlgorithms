#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[m])
                m = k;
        }

        if (m != i)
            swap(a[i], a[m]);

        cout << "Step " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
            cout << a[k] << " ";
        cout << endl;
    }
}

int main() {
    SETUP;

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    selection_sort(a, n);

    return 0;
}