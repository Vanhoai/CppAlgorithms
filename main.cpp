#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vector<int>> adj;
vector<bool> visited;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {}

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
        vvi edges(m);

        FOR(i, 0, m - 1) {
            vi v(2);
            cin >> v[0] >> v[1];
            edges[i] = v;
        }
    }

    return 0;
}
