#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/*
input:
2
AB
ABC

output:
AB BA
ABC ACB BAC BCA CAB CBA

*/

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));
    }

    return 0;
}