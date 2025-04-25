#include <iostream>
using namespace std;

// (A + B) % C = ((A % C) + (B % C)) % C
// (A - B) % C = ((A % C) - (B % C) + C) % C
// (A * B) % C = ((A % C) * (B % C)) % C
// (A ^ B) % C = (A % C) ^ B % C
// (A / B) % C = (A % C * B^(-1)) % C

// (A ^ B) % C
int powMod(int a, int b, int c) {
    int res = 1;
    a %= c;
    for (int i = 0; i < b; i++) {
        res *= a;
        res %= c;
    }

    return res;
}

int fibonacci(int n) {
    long long f[n + 1];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= 1000000007;
    }

    return f[n] % 1000000007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    cout << powMod(a, b, c) << endl;
    return 0;
}
