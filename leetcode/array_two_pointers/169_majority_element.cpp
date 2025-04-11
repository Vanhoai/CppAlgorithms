#include "bits/stdc++.h"
using namespace std;

/*
Leetcode 169: https://leetcode.com/problems/majority-element/

input
    2
    3
    3 2 3
    7
    2 2 1 1 1 2 2

output:
    3
    7
*/

int majorityElement(vector<int> &nums) {
    int count = 0;
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (count == 0)
            ans = nums[i];

        if (ans == nums[i])
            count++;
        else
            count--;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << majorityElement(a) << endl;
    }

    return 0;
}
