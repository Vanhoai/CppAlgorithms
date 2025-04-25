#include <iostream>
using namespace std;

bool check(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        int a = s[i] - '0';
        int b = s[i + 1] - '0';

        if (abs(a - b) == 1)
            return false;
    }

    return true;
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

        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);

        do {
            if (check(s)) {
                cout << s << endl;
            }
        } while (next_permutation(s.begin(), s.end()));
    }

    return 0;
}
