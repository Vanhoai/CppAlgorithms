#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    int k = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    nums[k++] = nums[nums.size() - 1];
    return k;
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

        int k = removeDuplicates(nums);
        for (int i = 0; i < k; i++)
            cout << nums[i] << " ";
        cout << endl;
    }

    return 0;
}
