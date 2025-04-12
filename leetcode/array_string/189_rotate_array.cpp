#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;

    vector<int> ans(n);
    for (int i = 0; i < k; i++)
        ans[i] = nums[n - k + i];

    for (int i = 0; i < n - k; i++)
        ans[k + i] = nums[i];

    for (int i = 0; i < n; i++)
        nums[i] = ans[i];
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
        rotate(nums, k);

        FOR(i, 0, n - 1) cout << nums[i] << " ";
        cout << endl;
    }

    return 0;
}
