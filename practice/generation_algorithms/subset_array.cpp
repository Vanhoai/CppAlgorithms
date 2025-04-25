#include <iostream>
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

int n, ok, X[10];

void init() {
    for (int i = 1; i <= n; i++)
        X[i] = 0;
}

void gen() {
    int i = n;
    while (i >= 1 && X[i] == 1) {
        X[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        X[i] = 1;
}

bool cmp(vector<int> a, vector<int> b) {
    if (a.size() != b.size())
        return a.size() < b.size();

    int i = 0, j = 0;
    bool check = true;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;

        i++;
        j++;
    }

    return true;
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
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        init();

        ok = 1;
        vector<vector<int>> res;
        while (ok) {
            vector<int> tmp;
            for (int i = 1; i <= n; i++) {
                if (X[i] != 0)
                    tmp.push_back(a[i]);
            }

            if (!tmp.empty())
                res.push_back(tmp);

            gen();
        }

        sort(res.begin(), res.end(), cmp);
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
