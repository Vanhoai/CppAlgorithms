#include <iostream>
#include <map>
using namespace std;

map<int, int> parent;
map<int, int> ranks;

int Find(int v) {
    if (parent[v] == v)
        return v;

    return parent[v] = Find(parent[v]);
}

void Union(int a, int b, int &mx) {
    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB)
        return;

    if (ranks[rootA] < ranks[rootB])
        swap(rootA, rootB);

    parent[rootB] = rootA;
    ranks[rootA] += ranks[rootB];
    mx = max(mx, ranks[rootA]);
}

int longestConsecutive(vector<int> &nums) {
    if (nums.empty())
        return 0;
    int mx = 1;
    parent.clear();
    ranks.clear();

    for (int i = 0; i < nums.size(); i++) {
        if (parent.find(nums[i]) != parent.end())
            continue;

        parent[nums[i]] = nums[i];
        ranks[nums[i]] = 1;

        if (parent.find(nums[i] - 1) != parent.end())
            Union(nums[i], nums[i] - 1, mx);

        if (parent.find(nums[i] + 1) != parent.end())
            Union(nums[i], nums[i] + 1, mx);
    }

    return mx;
}

// int dfs(unordered_map<int,int>& mp, int i){
//         int res = 0;
//         if(mp.find(i+1) != mp.end() && mp[i+1] == 0){
//             mp[i+1] = 1;
//             res += 1 + dfs(mp, i+1);
//         }
//         if(mp.find(i-1) != mp.end() && mp[i-1] == 0){
//             mp[i-1] = 1;
//             res += 1 + dfs(mp, i-1);
//         }
//         return res;
//     }

//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int ans = 1;
//         for(int i : nums) mp[i] = 0;
//         for(int i: nums){
//             if(mp[i] == 0) ans = max(ans, dfs(mp, i));
//         }
//         return nums.size()?ans:0;
//     }

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

        cout << longestConsecutive(nums) << endl;
    }

    return 0;
}
