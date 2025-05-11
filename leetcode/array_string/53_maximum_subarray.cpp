#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    long long ans = left;
    for (int i = left + 1; i < right; i++)
        ans &= i;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int L, R;
        cin >> L >> R;
        cout << rangeBitwiseAnd(L, R) << endl;
    }

    return 0;
}
