#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

void directed_swap(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                swap(a[i], a[j]);
        }

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

    directed_swap(a, n);
    return 0;
}