#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

ll factorial(int n) {
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

const int maxn = 1000005;
int f[maxn];

void solve(int a[], int n, int s) {
    ms(f, 0);
    FOR(i, 0, n) f[a[i]]++;

    ll res = 0;
    FOR(i, 0, n) {
        if (f[s - a[i]]) {

            if (a[i] == s - a[i]) {
                res += 1LL * factorial(f[a[i]] - 1);
            } else {
                res += 1LL * (f[a[i]] * f[s - a[i]]);
            }

            f[a[i]] = 0;
            f[s - a[i]] = 0;
        }
    }

    cout << res << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, s;
        cin >> n >> s;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        solve(a, n, s);
    }

    return 0;
}

ll factorial(int n) {
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

const int maxn = 1000005;
int f[maxn];

void solve(int a[], int n, int s) {
    ms(f, 0);
    FOR(i, 0, n) f[a[i]]++;

    ll res = 0;
    FOR(i, 0, n) {
        if (f[s - a[i]]) {

            if (a[i] == s - a[i]) {
                res += 1LL * factorial(f[a[i]] - 1);
            } else {
                res += 1LL * (f[a[i]] * f[s - a[i]]);
            }

            f[a[i]] = 0;
            f[s - a[i]] = 0;
        }
    }

    cout << res << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, s;
        cin >> n >> s;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        solve(a, n, s);
    }

    return 0;
}