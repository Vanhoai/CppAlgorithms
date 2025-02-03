#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int degree(int n, int k) {
    int ans = 0;
    for (int i = k; i <= n; i += k) {
        int m = i;
        while (m % k == 0) {
            ans++;
            m /= k;
        }
    }

    return ans;
}

int legendre(int n, int k) {
    int ans = 0;
    for (int i = k; i <= n; i *= k) {
        ans += n / i;
    }

    return ans;
}

int main() {
    SETUP;

    int n, k;
    cin >> n >> k;

    cout << degree(n, k) << endl;

    return 0;
}