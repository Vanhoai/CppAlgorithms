#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

void learn() {
    string s, v;
    getline(cin, s);
    getline(cin, v);

    // print size of string
    cout << "Size: " << s.size() << endl;
    cout << "Length: " << s.length() << endl;

    // access a character in string
    cout << "s[5]: " << s[5] << endl;
    cout << "s[0]: " << s[0] << endl;

    // loop through all characters in string
    for (int i = 0; i < s.size(); i++)
        cout << s[i];
    cout << endl;

    // concat two strings
    string sv = s + v;
    cout << sv << endl;

    // compare two strings
    if (s == v)
        cout << "s == v" << endl;
    else
        cout << "s != v" << endl;

    if (s > v)
        cout << "s > v" << endl;
    else
        cout << "s <= v" << endl;
}

int max_frequency(string s) {
    int a[256];
    memset(a, 0, sizeof(a));

    int size = s.size();
    for (int i = 0; i < size; i++)
        a[s[i]]++;

    int max = -1e9;
    char ans = s[0];
    for (int i = 0; i < 256; i++) {
        if (a[i] > max) {
            max = a[i];
            ans = (char) i;
        }
    }

    return ans;
}

int sum_string(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] - '0';

    return sum;
}

void advanced_for(string s) {
    for (auto c : s) {
        cout << c;
    }

    cout << endl;
}

int main() {
    SETUP;

    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;

    while (getline(ss, word, '_')) {
        cout << word << endl;
    }

    return 0;
}