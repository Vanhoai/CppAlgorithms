#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

string convert(string s, int r) {
    if (r > s.size() || r == 1)
        return s;

    string ans = "";

    int n = s.size() / r;
    vector<int> steps(n + 1, 0);

    steps[0] = 0;
    for (int i = 1; i < n + 1; i++)
        steps[i] = steps[i - 1] + 2 * (r - 1);

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < n + 1; k++) {
            if (i == 0) {
                int idx = steps[k];
                if (idx < s.size())
                    ans += s[idx];
            } else if (i == r - 1) {
                int idx = steps[k] + 1;
                if (idx < s.size())
                    ans += s[idx];
            } else {
                int idx1 = steps[k] + 1;
                int idx2 = steps[k] + 1 + 2 * (r - i - 1);

                if (idx1 < s.size())
                    ans += s[idx1];
                if (idx2 < s.size())
                    ans += s[idx2];

                steps[k] += 1;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        string s;
        cin >> s >> n;
        cout << convert(s, n) << endl;
    }

    return 0;
}
