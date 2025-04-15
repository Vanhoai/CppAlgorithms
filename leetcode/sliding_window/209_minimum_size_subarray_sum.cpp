#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int L = 0, R = 0;
    int sum = 0;
    int ans = INT_MAX;

    while (R < n) {
        sum += nums[R++];
        while (sum >= target) {
            ans = min(ans, R - L);
            sum -= nums[L++];
        }
    }

    if (ans == INT_MAX)
        return 0;

    return ans;
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
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        FOR(i, 0, n - 1) cin >> nums[i];
        cout << minSubArrayLen(k, nums) << endl;
    }

    return 0;
}
