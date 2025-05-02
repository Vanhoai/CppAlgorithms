#include <iostream>
using namespace std;

int singleNumber(vector<int> &nums) {
    int sum = 0;
    for (int num : nums)
        sum ^= num;

    return sum;
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
        cout << singleNumber(nums) << endl;
    }

    return 0;
}
