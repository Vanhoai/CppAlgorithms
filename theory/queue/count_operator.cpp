#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int solve(int s, int t) {
    queue<pi> q;
    q.push(MP(s, 0));

    set<int> se;
    se.insert(s);

    while (!q.empty()) {
        pi it = q.front();
        q.pop();

        if (it.F == t)
            return it.S;

        if (it.F > 1 && se.count(it.F - 1) == 0) {
            q.push(MP(it.F - 1, it.S + 1));
            se.insert(it.F - 1);
        }

        if (it.F < t && se.count(it.F * 2) == 0) {
            q.push(MP(it.F * 2, it.S + 1));
            se.insert(it.F * 2);
        }
    }

    return -1;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }

    return 0;
}