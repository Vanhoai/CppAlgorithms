#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Character in two strings
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S1, S2: string (size <= 1000)
 *
 * output: print all characters exists in both strings
 *
 * @example
 *      input:
 *          S1: Python java PHP
 *          S2: Project
 *
 *      output: Pjot
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);

        int a[256];
        memset(a, 0, sizeof(a));

        for (int i = 0; i < s1.size(); i++)
            a[s1[i]] = 1;

        for (char c : s2) {
            if (a[c] == 1)
                a[c] = 2;
        }

        for (int i = 0; i < 256; i++) {
            if (a[i] == 2) {
                cout << (char) i;
            }
        }

        cout << endl;
    }

    return 0;
}