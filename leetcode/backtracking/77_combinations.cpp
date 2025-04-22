#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

void gen(vector<int> &X, int n, int k, bool &ok) {
    int i = k - 1;
    while (i >= 0 && X[i] == n - k + i + 1)
        i--;

    if (i < 0) {
        ok = true;
    } else {
        X[i]++;
        for (int j = i + 1; j < k; ++j)
            X[j] = X[j - 1] + 1;
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> v;
    vector<int> X(k);
    for (int i = 0; i < k; i++)
        X[i] = i + 1;

    v.push_back(X);
    bool ok = false;
    do {
        gen(X, n, k, ok);
        if (!ok)
            v.push_back(X);
    } while (!ok);

    return v;
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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v = combine(n, k);
        for (const auto &comb : v) {
            for (int num : comb)
                cout << num << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
