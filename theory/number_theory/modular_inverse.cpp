#include "bits/stdc++.h"
using namespace std;

// (A / B) % C = (A % C * B^(-1)) % C
// (A.B) % M = 1 for all gcd(A, M) = 1
// B is module inversion of A with M
// -> (A / B) % M = [(A % M) * (B^-1 % M)] % M

// Extended Euclid
// ax + by = gcd(a, b)
// -> ax + my = 1
// -> (ax + my) % m = 1 % m
// -> ax % m = 1 % m (because my % m = 0)
// -> ax % m = 1
// -> x is module inversion which can be find with extended euclidean algorithms

// if m is prime number
// with little fermat's theorem (m is prime number)
// -> A^(m - 1) % m = 1
// -> A^-1 . A ^(m - 1) % m = A^-1
// -> A^(m - 2) % m = A^-1
// -> A^-1 = A^(m - 2) % m
// -> a^b % c with binpow

int x, y, g;

// O(log min(a, b))
void extended_gcd(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        g = a;
        return;
    }

    extended_gcd(b, a % b);
    int x1 = x;
    x = y;
    y = x1 - a / b * y;
}

// ax + by = gcd(a, b)
int modular_inverse(int a, int m) {
    extended_gcd(a, m);
    // avoid x negative
    return (x % m + m) % m;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b = b >> 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Calculate (A / B) % M
    int a, b, m;
    cin >> a >> b >> m;
    cout << (a * modular_inverse(b, m) % m) << endl;

    // Calculate modular inverse a m
    cout << modular_inverse(a, m) << endl;
    cout << bin_pow(a, m - 2, m) << endl;

    return 0;
}
