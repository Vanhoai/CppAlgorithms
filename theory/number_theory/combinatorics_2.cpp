#include <iostream>
using namespace std;

int Ckn(int n, int k) {
    int res = 1;
    k = min(k, n - k);
    for (int i = 0; i < k; i++) {
        res *= n - i;
        res /= i + 1;
    }

    return res;
}

int Akn(int n, int k) {
    int res = 1;
    for (int i = 1; i <= k; i++) {
        res *= n - i + 1;
        res /= i;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    cout << Ckn(n, k) << endl;

    return 0;
}
