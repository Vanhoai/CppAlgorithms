#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
input:
2*x^5 + 3*x^2 + 5*x^0
4*x^5 + 2*x^1 + 10*x^0

output:
#Test 1: 6*x^5 + 3*x^2 + 2*x^1 + 15*x^0
*/

int sub_num(string s) {
    string num = "0";
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]))
            return stoi(num);
        else
            num += s[i];
    }

    return stoi(num);
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string p1, p2;
        getline(cin, p1);
        getline(cin, p2);

        stringstream ss1(p1);
        stringstream ss2(p2);
        string word;

        map<int, int> mp;
        while (ss1 >> word) {
            if (word != "+") {
                int l = word[word.size() - 1] - '0';
                int n = sub_num(word);

                mp[l] = n;
            }
        }

        while (ss2 >> word) {
            if (word != "+") {
                int l = word[word.size() - 1] - '0';
                int n = sub_num(word);

                if (mp.find(l) != mp.end())
                    mp[l] += n;
                else
                    mp[l] = n;
            }
        }

        vector<pair<int, int>> res;
        for (auto it : mp)
            res.push_back(make_pair(it.first, it.second));

        cout << "#Test " << TC + 1 << ": ";
        for (int i = res.size() - 1; i >= 0; i--) {
            cout << res[i].second << "*" << "x^" << res[i].first;
            if (i != 0)
                cout << " + ";
        }

        cout << endl;
    }

    return 0;
}