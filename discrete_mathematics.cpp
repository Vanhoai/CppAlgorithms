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
    int maxtrix[N][N];
    int size;
    vector<string> bits;
    bitset<5> x, x_, y, y_, z, z_, t, t_;
    int dbits[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    map<int, map<int, int>> mapping_num = {{1, {{1, 1}, {0, 2}}},
                                           {2, {{1, 3}, {0, 4}}},
                                           {3, {{1, 5}, {0, 6}}},
                                           {4, {{1, 7}, {0, 8}}}};

    map<int, map<int, string>> mapping_chars = {
        {1, {{1, "x"}, {0, "x\u0305"}}},
        {2, {{1, "y"}, {0, "y\u0305"}}},
        {3, {{1, "z"}, {0, "z\u0305"}}},
        {4, {{1, "t"}, {0, "t\u0305"}}}};

    void init() {
        // mark bits for each set
        x.set(1), x.set(2);
        x_.set(3), x_.set(4);
        y.set(2), y.set(3);
        y_.set(1), y_.set(4);
        z.set(1), z.set(2);
        z_.set(3), z_.set(4);
        t.set(2), t.set(3);
        t_.set(1), t_.set(4);
    }

    vector<string> dnf() {
        vector<string> characters(size);
        FOR(i, 0, size - 1) {
            string tmp = "";
            FOR(k, 0, 3) tmp += mapping_chars[k + 1][bits[i][k] - '0'];
            characters[i] = tmp;
        }

        return characters;
    }

    bitset<5> pick(int c) {
        switch (c) {
        case 1:
            return x;
        case 2:
            return x_;
        case 3:
            return y;
        case 4:
            return y_;
        case 5:
            return z;
        case 6:
            return z_;
        case 7:
            return t;
        case 8:
            return t_;
        default:
            return x;
        }
    }

public:
    Karf(vector<string> bits) {
        init();
        this->size = bits.size();
        this->bits = bits;
    }

    void find_dnf() {
        vector<string> dnf = this->dnf();
        FOR(i, 0, size - 1) cout << dnf[i] << endl;
        cout << endl;
    }

    // void cells(vector<string> bits) {
    //     // update size
    //     int n = bits.size();
    //     size = n;

    //     fx.resize(size);
    //     FOR(i, 0, size - 1) {
    //         string tmp = "";
    //         FOR(k, 0, 3)
    //         tmp += char(mapping_num[k + 1][bits[i][k] - '0'] + '0');
    //         fx[i] = tmp;
    //     }
    // }
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
// f(1) = {1010,1110,0110,1011,0111,0011,1001,1101,1000,1100,0100,0000}

// 12 1
// 1010
// 1110
// 0110
// 1011
// 0111
// 0011
// 1001
// 1101
// 1000
// 1100
// 0100
// 0000

Karf input() {
    int n, check;
    cin >> n >> check;
    vector<string> bits;
    cin.ignore();
    FOR(i, 0, n - 1) {
        string w;
        getline(cin, w);
        bits.PB(w);
    }

    Karf karf(bits);
    return karf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Karf karf = input();
    karf.find_dnf();

    return 0;
}
