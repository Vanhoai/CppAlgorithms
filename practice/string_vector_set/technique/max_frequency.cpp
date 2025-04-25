#include <iostream>
using namespace std;

/**
 * Max Frequency
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string to be analyzed (size <= 1000)
 *
 * output: print char with max frequency
 *
 * @example
 *      input: aaababca
 *      output: a
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

        for (int i = 0; i < s.size(); i++)
            a[s[i]]++;

        int max = -1e9;
        char ans = s[0];

        for (int i = 0; i < 256; i++) {
            if (a[i] >= max) {
                max = a[i];
                ans = (char) i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
