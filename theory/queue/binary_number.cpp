#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

void solve(int n) {
    vector<string> res;

    queue<string> q;
    q.push("0");
    q.push("1");

    while (true) {
        string s = q.front();
        q.pop();

        if (s.size() >= n)
            break;

        res.push_back(s);

        q.push(s + "0");
        q.push(s + "1");
    }

    FOR(i, 0, sz(res)) cout << res[i] << endl;
}

int main() {
    SETUP;
    solve(5);
    return 0;
}