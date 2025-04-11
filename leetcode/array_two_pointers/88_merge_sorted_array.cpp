#include "bits/stdc++.h"
using namespace std;

/*
Leetcode 88: https://leetcode.com/problems/merge-sorted-array

input
    2
    6 3
    1 2 3 0 0 0
    2 5 6
    1 0
    1

output:
    1 2 2 3 5 6
    1

*/

void merge(vector<int> &a, int m, vector<int> &b, int n) {
    int r = a.size() - 1;

    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] > b[j])
            a[r--] = a[i--];
        else
            a[r--] = b[j--];
    }

    while (i >= 0)
        a[r--] = a[i--];

    while (j >= 0)
        a[r--] = b[j--];
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n - m; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        merge(a, n - m, b, m);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
