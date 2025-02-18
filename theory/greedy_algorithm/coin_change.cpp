#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int main() {
    SETUP;

    int a[6] = {1, 2, 5, 10, 20, 50};

    int s;
    cin >> s;

    mii mp;

    for (int i = 5; i >= 0; i--) {
        mp[a[i]] = s / a[i];
        s %= a[i];
    }

    for (auto it : mp)
        cout << it.F << ": " << it.S << endl;

    return 0;
}