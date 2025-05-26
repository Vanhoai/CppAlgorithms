#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string gen(string s) {
    int n = s.size();
    if (n == 1)
        return s;

    int i = n - 2;

    while (s[i] >= s[i + 1])
        i--;

    if (i == -1)
        return "BIGGEST";

    int j = n - 1;
    while (s[j] < s[i])
        j--;

    swap(s[j], s[i]);
    sort(s.begin() + i + 1, s.end());

    return s;
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
        cin >> n >> s;
        cout << n << " " << gen(s) << endl;
    }

    return 0;
}
