#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

bool canJump(vector<int> &nums) {
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
        if (i + nums[i] >= n)
            n = i;
    }

    return n == 0;
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
        cout << canJump(nums) << endl;
    }

    return 0;
}
