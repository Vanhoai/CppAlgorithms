#include <iostream>
#include <sstream>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }

    return result;
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
        stringstream ss(s);
        vector<string> tokens;
        string w;
        while (ss >> w)
            tokens.push_back(w);

        string a = tokens[0];
        string b = tokens[1];
        cout << addBinary(a, b) << endl;
    }

    return 0;
}
