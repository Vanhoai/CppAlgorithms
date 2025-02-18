#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
2
4

1≤T≤100; 1≤N≤10^4

output:
66 88 6666 6886
66 88 6666 6886 8668 8888 666666 668866 686686 688886

*/

int n, ok;
string s;
vector<string> res;

void gen() {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '8') {
        s[i] = '6';
        i--;
    }

    if (i == -1)
        ok = 0;
    else
        s[i] = '8';
}

void init() {
    for (int i = 1; i <= 13; i++) {
        s = string(i, '6');
        ok = 1;
        while (ok) {
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            res.push_back(s + tmp);

            gen();
        }
    }
}

int main() {
    SETUP;
    init();

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;

        int i = 0;
        while (i < n) {
            cout << res[i++] << " ";
        }

        cout << endl;
    }

    return 0;
}