#include <iostream>
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    cout << degree(n, k) << endl;

    return 0;
}
