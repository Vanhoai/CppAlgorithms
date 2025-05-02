#include <iostream>
using namespace std;

int hammingWeight(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }

    return count;
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
        int n;
        cin >> n;
        cout << hammingWeight(n) << endl;
    }

    return 0;
}
