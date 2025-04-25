#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;

void factorize(int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }

    if (n > 1)
        mp[n]++;
}

int d(int n) {
    int d = 1;
    for (auto it : mp) {
        d *= (it.second + 1);
    }

    return d;
}

int u(int n) { return pow(n, d(n) / 2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    factorize(n);

    cout << "d(" << n << ") = " << d(n) << endl;
    cout << "u(" << n << ") = " << u(n) << endl;

    return 0;
}
