#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string w, res = "";
        while (ss >> w) {
            char f = w[0];
            res += f;
        }

        cout << res << endl;
    }

    return 0;
}
