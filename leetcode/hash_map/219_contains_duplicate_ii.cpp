#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) != mp.end()) {
            if (i - mp[nums[i]] <= k)
                return true;
            else
                mp[nums[i]] = i;
        } else
            mp[nums[i]] = i;
    }

    return false;
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
        cout << containsNearbyDuplicate(nums, k) << endl;
    }

    return 0;
}
