#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
3
Nam Lan Phi

output:
Lan Nam Phi
Lan Phi Nam
Nam Lan Phi
Nam Phi Lan
Phi Nam Lan
Phi Lan Nam
*/

int n, ok, X[100];

void init() { REP(i, 1, n) X[i] = i; }

void gen() {
    int i = n - 1;
    while (i >= 1 && X[i] > X[i + 1])
        i--;

    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j >= 1 && X[i] > X[j])
            --j;

        swap(X[i], X[j]);
        reverse(X + i + 1, X + n + 1);
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);
        vector<string> words;

        stringstream ss(s);
        string word;
        while (ss >> word)
            words.push_back(word);

        sort(words.begin(), words.end());
        init();
        ok = 1;
        while (ok) {
            for (int i = 1; i <= n; i++)
                cout << words[X[i] - 1] << " ";

            cout << endl;
            gen();
        }
    }

    return 0;
}