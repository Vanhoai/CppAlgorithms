#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int num;
        cin >> num;

        vector<int> v;
        FOR(i, 0, num) {
            string s;
            cin >> s;

            if (s == "push") {
                int n;
                cin >> n;
                v.push_back(n);
            }

            if (s == "show") {
                FOR(i, 0, sz(v)) cout << v[i] << " ";
                cout << endl;
            }

            if (s == "pop") {
                v.pop_back();
            }
        }
    }

    return 0;
}