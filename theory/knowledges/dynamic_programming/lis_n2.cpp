#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i; k++) {
            if (a[k] < a[i])
                dp[i] = max(dp[i], dp[k] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
