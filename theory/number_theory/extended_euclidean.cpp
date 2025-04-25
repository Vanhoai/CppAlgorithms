#include <iostream>
using namespace std;

int x, y, g;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;
    extended_gcd(a, b);
    cout << x << " " << y << endl;

    return 0;
}
