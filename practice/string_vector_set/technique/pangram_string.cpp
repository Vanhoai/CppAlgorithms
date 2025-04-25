#include <iostream>
using namespace std;

/**
 * Pangram String
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: YES/NO
 *
 * @example
 *      input: thequickbrownfoxjumpsoverthelazydog
 *      output: YES
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        int a[256];
        memset(a, 0, sizeof(a));

        for (char c : s)
            a[c] = 1;

        int ok = 1;
        for (int i = 97; i <= 122; i++) {
            if (a[i] == 0) {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
