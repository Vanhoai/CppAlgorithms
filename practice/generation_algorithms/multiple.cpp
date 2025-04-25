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

/**
input
3
2
5
11

output:
90
90
99
*/

ll divisible[501];
vector<string> v;
string s;
int ok;

void gen() {
    int i = s.size();
    while (i >= 0 && s[i] == '9') {
        s[i] = '0';
        --i;
    }

    if (i == -1)
        ok = 0;
    else
        s[i] = '9';
}

void init() {
    s = "000000000000";
    ok = 1;
    while (ok) {
        v.push_back(s);
        gen();
    }

    for (int i = 1; i <= 500; i++) {
        for (string it : v) {
            ll tm = stoll(it);
            if (tm != 0 && tm % i == 0) {
                divisible[i] = tm;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cout << divisible[n] << endl;
    }

    return 0;
}
