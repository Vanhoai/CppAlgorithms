#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int u(int n, int d, int u1) { return u1 + (n - 1) * d; }
int s(int n, int q, int s1) { return s1 * pow(q, n - 1); }

int su(int n, int u1, int un) { return n * (u1 + un) / 2; }
int ss(int n, int u1, int q) { return (u1 * (pow(q, n) - 1)) / (q - 1); }

int main() {
    SETUP;

    int n, d, u1, un, q, s1, sn;
    cin >> n >> d >> u1 >> un >> q >> s1 >> sn;

    cout << u(n, d, u1) << endl;
    cout << s(n, q, s1) << endl;

    cout << su(n, u1, un) << endl;
    cout << ss(n, u1, q) << endl;

    return 0;
}