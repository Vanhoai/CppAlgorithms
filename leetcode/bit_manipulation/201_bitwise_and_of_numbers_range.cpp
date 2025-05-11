#include <iostream>
using namespace std;

int maxSubArray(vector<int> &nums) {
    int sum = 0;
    int mx = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        sum = max(sum + nums[i], nums[i]);
        mx = max(mx, sum);
    }

    return mx;
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
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << maxSubArray(nums) << endl;
    }

    return 0;
}
