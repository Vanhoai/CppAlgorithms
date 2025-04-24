#include <iostream>
#include <unordered_set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

int nextNumber(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    if (n < 0)
        return false;

    unordered_set<int> se;
    se.insert(n);
    do {
        n = nextNumber(n);
        if (n == 1)
            return true;
        if (se.find(n) != se.end())
            return false;

        se.insert(n);
    } while (true);

    return false;
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
        cin >> n;
        cout << isHappy(n) << endl;
    }

    return 0;
}
