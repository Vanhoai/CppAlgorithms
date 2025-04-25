#include <iostream>
using namespace std;

/**
input
2
2
4

1≤T≤10; 1≤N≤30

output:
00 11
00 11 0000 0110 1001 1111
*/

int n, ok, X[100];
string s;
vector<string> res;

void gen() {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1') {
        s[i] = '0';
        i--;
    }

    if (i == -1)
        ok = 0;
    else
        s[i] = '1';
}

void init() {
    for (int i = 1; i <= 15; i++) {
        s = string(i, '0');
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;

        int i = 0;
        while (res[i].size() <= n) {
            cout << res[i++] << " ";
        }

        cout << endl;
    }

    return 0;
}
