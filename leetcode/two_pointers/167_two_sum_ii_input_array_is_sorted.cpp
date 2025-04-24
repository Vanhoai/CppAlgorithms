#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

vector<int> twoSum(vector<int> &numbers, int target) {
    int L = 0, R = numbers.size() - 1;
    while (L < R) {
        int sum = numbers[L] + numbers[R];
        if (sum == target)
            return {L + 1, R + 1};

        if (sum < target)
            ++L;
        else
            --R;
    }

    return {-1, -1};
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
        FOR(i, 0, n - 1) cin >> nums[i];

        vector<int> result = twoSum(nums, target);
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}
