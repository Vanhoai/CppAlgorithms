#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

void insertion_sort(int a[], int n) {

    cout << "Step 0: ";
    cout << a[0] << endl;

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        cout << "Step " << i << ": ";
        for (int k = 0; k <= i; k++)
            cout << a[k] << " ";
        cout << endl;
    }
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

    insertion_sort(a, n);

    return 0;
}
