#include <iostream>
#include <sstream>
using namespace std;

/**
 * Sort Word by size
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: print sorted word in string
 *
 * @example
 *      input: aa abc aaa a bc z
 *      output: a z aa bc abc aaa
 */

bool cmp(string a, string b) { return a.size() < b.size(); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        vector<string> v;
        stringstream ss(s);
        string word;

        while (ss >> word)
            v.push_back(word);

        sort(v.begin(), v.end(), cmp);

        for (string w : v)
            cout << w << " ";

        cout << endl;
    }

    return 0;
}
