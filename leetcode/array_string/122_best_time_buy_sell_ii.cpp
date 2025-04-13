#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

int maxProfit(vector<int> &prices) {
    int mn = INT_MAX;
    int ans = 0;

    for (int i = 0; i < prices.size(); i++) {
        mn = min(mn, prices[i]);
        ans = max(ans, prices[i] - mn);
    }

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
        int n;
        cin >> n;
        vector<int> nums(n);
        FOR(i, 0, n - 1) cin >> nums[i];
        cout << maxProfit(nums) << endl;
    }

    return 0;
}
