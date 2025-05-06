#include <iostream>
using namespace std;

string intToRoman(int num) {
    const int maxn = 13;
    int n[maxn] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string strs[maxn] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                         "XL", "X",  "IX", "V",  "IV", "I"};

    int i = 0;
    string roman = "";

    while (num > 0) {
        if (num >= n[i]) {
            roman = roman + strs[i];
            num -= n[i];
        } else {
            i++;
        }
    }

    return roman;
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
        int num;
        cin >> num;
        cout << intToRoman(num) << endl;
    }

    return 0;
}
