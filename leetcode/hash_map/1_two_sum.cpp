#include <iostream>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> mp;

    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (mp[target - nums[i]])
            return {mp[target - nums[i]], i};

        mp[nums[i]] = i;
    }
    return {0, 0};
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
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            cin >> nums[i];

        vector<int> result = twoSum(nums, target);
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}
