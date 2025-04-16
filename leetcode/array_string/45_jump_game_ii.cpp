#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

int jump(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
        return 0;

    int dp[n];
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] >= 0 && i + nums[i] >= n - 1)
            return dp[i] + 1;

        if (dp[i] >= 0) {
            for (int j = 0; j < nums[i] && i + j + 1 < n; j++) {
                int k = i + 1 + j;
                if (dp[k] == -1)
                    dp[k] = dp[i] + 1;
                else
                    dp[k] = min(dp[k], dp[i] + 1);
            }
        }
    }

    return dp[n - 1];
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
        vector<int> nums(n);
        FOR(i, 0, n - 1) cin >> nums[i];
        cout << jump(nums) << endl;
    }

    return 0;
}
