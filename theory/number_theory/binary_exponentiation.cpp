#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int binary_pow(int a, int b, int c) {
    if (b == 0)
        return 1;
    int x = binary_pow(a, b / 2, c);
    if (b & 1)
        return x * x * a % c;
    return x * x % c;
}

int bin_pow(int a, int b, int c) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= c;
        }

        b /= 2;
        a *= a;
        a %= c;
    }

    return res;
}

int main() {
    SETUP;

    int a, b, c;
    cin >> a >> b >> c;

    cout << binary_pow(a, b, c) << endl;
    cout << bin_pow(a, b, c) << endl;

    return 0;
}