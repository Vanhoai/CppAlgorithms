#include <iostream>
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
    int slow = n;
    int fast = nextNumber(n);
    while (fast != 1 && fast != slow) {
        slow = nextNumber(slow);
        fast = nextNumber(nextNumber(fast));
    }

    return fast == 1;
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
