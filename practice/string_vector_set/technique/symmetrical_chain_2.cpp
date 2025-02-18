#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Symmetrical Chain 2
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: YES/NO
 *
 * @example
 *      input: AbcdbcbA
 *      output: YES
 */

int is_symmetrical(string s) {
    int count = 0;

    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        if (s[i] != s[j])
            count++;
        i++;
        j--;
    }

    if (s.size() % 2 == 0 && count == 0)
        return 0;

    if (count > 1)
        return 0;

    return 1;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        cout << (is_symmetrical(s) ? "YES" : "NO") << endl;
    }

    return 0;
}