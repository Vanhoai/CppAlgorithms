#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
4 2
3 2

output:
0011
0101
0110
1001
1010
1100
011
101
110

 */

int n, k, ok, g[100];
void init() { REP(i, 1, n) g[i] = 0; }

void gen() {
    int i = n;
    while (i >= 1 && g[i] == 1) {
        g[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        g[i] = 1;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        init();

        ok = 1;
        vector<string> res;
        while (ok) {
            int count = 0;
            string s = "";
            REP(i, 1, n) {
                s += to_string(g[i]);

                if (g[i])
                    count++;
            }

            if (count == k)
                res.push_back(s);

            gen();
        }

        for (auto it : res)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}