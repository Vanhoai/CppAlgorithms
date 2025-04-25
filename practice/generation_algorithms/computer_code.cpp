#include <iostream>
using namespace std;

/**
input
2

output:
AB11
AB12
AB21
AB22
BA11
BA12
BA21
BA22

*/

int n, ok, X[100];

void init() {
    for (int i = 1; i <= n; i++)
        X[i] = 1;
}

void gen() {
    int i = n;
    while (i >= 1 && X[i] == n)
        i--;

    if (i == 0)
        ok = 0;
    else {
        X[i]++;
        for (int j = i + 1; j <= n; j++)
            X[j] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    string s;

    vector<string> akn;
    init();
    ok = 1;
    while (ok) {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(X[i]);

        akn.push_back(s);
        gen();
    }

    vector<string> p;
    for (int i = 0; i < n; i++)
        s += i + 'A';

    do {
        p.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j < akn.size(); j++) {
            cout << p[i] << akn[j] << endl;
        }
    }

    return 0;
}
