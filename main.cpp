#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, cnt, ok, a[100];

void init() {
    cnt = 1;
    a[1] = n;
}

void gen() {
    int i = cnt;
    while (i >= 1 && a[i] == 1)
        --i;

    if (i == 0)
        ok = 0;
    else {
        a[i]--;
        int miss = cnt - i + 1;
        int x = miss / a[i];
        int m = miss % a[i];

        cnt = i;
        for (int j = 0; j < x; j++) {
            a[cnt + 1] = a[i];
            cnt++;
        }

        if (m > 0) {
            a[cnt + 1] = m;
            cnt++;
        }
    }
}

int main() {
    SETUP;

    cin >> n;
    init();

    ok = 1;
    while (ok) {
        for (int i = 1; i <= cnt; i++)
            cout << a[i] << " ";

        cout << endl;
        gen();
    }

    return 0;
}