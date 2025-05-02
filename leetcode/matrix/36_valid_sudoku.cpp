#include <iostream>
using namespace std;

#define ms(s, n)      memset(s, n, sizeof(s))
#define all(a)        a.begin(), a.end()
#define sz(a)         int((a).size())
#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

#define PB push_back
#define MP make_pair
#define F  first
#define S  second

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 1;
const int DEG = (int) 10001;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValidSudoku(vector<vector<char>> &board) {
    // check row and colum valid
    FOR(i, 0, 8) {
        bool row[9] = {false}, col[9] = {false};

        FOR(j, 0, 8) {
            if (board[i][j] != '.') {
                if (row[board[i][j] - '1'])
                    return false;

                row[board[i][j] - '1'] = true;
            }

            if (board[j][i] != '.') {
                if (col[board[j][i] - '1'])
                    return false;

                col[board[j][i] - '1'] = true;
            }
        }
    }

    // check subgrid valid
    FOR(i, 0, 2) FOR(j, 0, 2) {
        int ic = i * 3 + 1;
        int jc = j * 3 + 1;

        bool subgrid[9] = {false};
        if (board[ic][jc] != '.')
            subgrid[board[ic][jc] - '1'] = true;

        FOR(k, 0, 7) {
            int ix = ic + dx[k];
            int iy = jc + dy[k];

            if (board[ix][iy] != '.') {
                if (subgrid[board[ix][iy] - '1'])
                    return false;

                subgrid[board[ix][iy] - '1'] = true;
            }
        }
    }

    return true;
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
        vector<vector<char>> board(9, vector<char>(9));
        FOR(i, 0, 8) FOR(k, 0, 8) cin >> board[i][k];
        cout << isValidSudoku(board) << endl;
    }

    return 0;
}
