#include "bits/stdc++.h"
using namespace std;

long long C[1001][1001];

// Calculate Ckn base on pascal triangle

void init() {
    for (int i = 0; i <= 1000; i++) {
        for (int k = 0; k <= 1000; k++) {
            if (k == 0 || i == k)
                C[i][k] = 1;
            else {
                C[i][k] = C[i - 1][k - 1] + C[i - 1][k];
                C[i][k] %= 1000000007;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    init();
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        cout << C[n][k] << endl;
    }

    return 0;
}
