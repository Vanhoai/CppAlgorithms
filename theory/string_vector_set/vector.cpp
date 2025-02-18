#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

void basic() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // iterator
    cout << "Print with iterator" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
    auto last = v.end() - 1;
    cout << "Last element: " << *last << endl;
}

ll stoll_own(string s) {
    ll res = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        int digit = s[i] - '0';
        res += digit * pow(10, size - i - 1);
    }

    return res;
}

string to_string_own(ll n) {
    string res = "";
    while (n) {
        char digit = (char) (n % 10) + '0';
        res = digit + res;
        n /= 10;
    }

    return res;
}

int main() {
    SETUP;

    ll n;
    cin >> n;
    cout << to_string_own(n) << endl;

    return 0;
}