#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

typedef vector<char> vc;
typedef vector<vc> vvc;

int n, m;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void dfs(vvc &grid, int i, int j) {
    grid[i][j] = 0;
    FOR(k, 0, 3) {
        int ix = i + dx[k];
        int iy = j + dy[k];

        if (ix >= 0 && ix < n && iy >= 0 && iy < m && grid[ix][iy] == '1')
            dfs(grid, ix, iy);
    }
}

int numIslands(vvc &grid) {
    n = grid.size();
    m = grid[0].size();

    int count = 0;
    FOR(i, 0, n - 1) FOR(k, 0, m - 1) {
        if (grid[i][k] == '1') {
            count++;
            dfs(grid, i, k);
        }
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
    while (TC--) {
        int n, m;
        cin >> n >> m;

        vvc grid(n, vc(m, '0'));
        FOR(i, 0, n - 1) FOR(k, 0, m - 1) cin >> grid[i][k];
        cout << numIslands(grid) << endl;
    }

    return 0;
}
