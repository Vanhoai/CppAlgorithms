#include <bitset>
#include <iostream>
#include <map>
#include <string>
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

const int N = 5;
const int MAXN = 1001;

class Karf {
private:
    int size;
    int matrix[N][N];

    const map<string, bitset<5>> table = {
        {"x", bitset<5>("00110")}, {"x_", bitset<5>("11000")},
        {"y", bitset<5>("01100")}, {"y_", bitset<5>("10010")},
        {"z", bitset<5>("00110")}, {"z_", bitset<5>("11000")},
        {"t", bitset<5>("01100")}, {"t_", bitset<5>("10010")},
    };

    const map<string, bitset<5>> table_col = {
        {"x", bitset<5>("00110")},
        {"x_", bitset<5>("11000")},
        {"y", bitset<5>("01100")},
        {"y_", bitset<5>("10010")},
    };

    const map<string, bitset<5>> table_row = {
        {"z", bitset<5>("00110")},
        {"z_", bitset<5>("11000")},
        {"t", bitset<5>("01100")},
        {"t_", bitset<5>("10010")},
    };

public:
    Karf() {
        ms(matrix, 0);
        size = 0;
    }

    void input() {
        FOR(i, 1, 4) FOR(k, 1, 4) {
            int x;
            cin >> x;
            matrix[i][k] = x;
            if (x == 1)
                size++;
        }
    }

    void dnf() {
        FOR(r, 1, 4) {
            FOR(c, 1, 4) {
                int bit = matrix[r][c];
                if (bit == 0)
                    continue;

                // \u0305

                string col = "";
                for (auto it : table_col) {
                    bitset<5> bs = it.second;
                    if (bs.test(c))
                        col += it.first;
                }

                string row = "";
                for (auto it : table_row) {
                    bitset<5> bs = it.second;
                    if (bs.test(r))
                        row = it.first + row;
                }

                col += row;
                cout << r << " " << c << ": ";
                cout << col << endl;
            }
        }
    }

    void in() {
        cout << "size: " << size << endl;
        FOR(i, 1, 4) {
            FOR(k, 1, 4) cout << matrix[i][k] << " ";
            cout << endl;
        }
    }
};

//     Kar(f)
//             x           x^
//          1     2     3     4
//       |-----------------------|
//     1 |     |     |     |     |  t^
//  z    |-----|-----|-----|-----|
//     2 |     |     |     |     |
//       |-----|-----|-----|-----|  t
//     3 |     |     |     |     |
//  z^   |-----|-----|-----|-----|
//     4 |     |     |     |     |  t^
//       |-----|-----------|-----|
//          y^       y        y^
//
// 1 1 0 1
// 0 1 0 0
// 0 1 1 1
// 1 0 1 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Karf karf;
    karf.input();
    // karf.in();
    karf.dnf();

    return 0;
}
