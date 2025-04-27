#include <iostream>
using namespace std;

int countSubarrays(vector<int> &nums) {
    int count = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
        if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1])
            count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << countSubarrays(nums) << endl;
    }

    return 0;
}
