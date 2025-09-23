#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char c;
    cin >> c;
    cout << (char) c << endl;

    // check c is a lowercase letter
    cout << islower(c) << endl;

    // check c is a uppercase letter
    cout << isupper(c) << endl;

    // check c is a digit
    cout << isdigit(c) << endl;

    // check c is a letter
    cout << isalpha(c) << endl;

    // to lower case
    cout << (char) tolower(c) << endl;

    // to upper case
    cout << (char) toupper(c) << endl;

    return 0;
}
