#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

const int maxn = 10000001;
long long dp[maxn];

void init() {
    dp[0] = 0;
    dp[1] = 1;
    FOR(i, 2, maxn) {
        dp[i] = 1LL * i * dp[i - 1];
        dp[i] %= MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}
