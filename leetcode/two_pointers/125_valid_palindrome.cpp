#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

bool isPalindrome(string s) {
    int L = 0, R = s.size() - 1;

    while (L < R) {
        if (!isalnum(s[L])) {
            L++;
            continue;
        }
        if (!isalnum(s[R])) {
            R--;
            continue;
        }
        if (tolower(s[L]) != tolower(s[R]))
            return false;
        else {
            L++;
            R--;
        }
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
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);
        cout << isPalindrome(s) << endl;
    }

    return 0;
}
