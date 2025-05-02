#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed <<= 1;
        reversed |= n & 1;
        n >>= 1;
    }

    return reversed;
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
        uint32_t n;
        cin >> n;
        cout << reverseBits(n) << endl;
    }

    return 0;
}
