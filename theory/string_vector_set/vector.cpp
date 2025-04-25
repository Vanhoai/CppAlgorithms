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

void basic() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // iterator
    cout << "Print with iterator" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
    auto last = v.end() - 1;
    cout << "Last element: " << *last << endl;
}

ll stoll_own(string s) {
    ll res = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        int digit = s[i] - '0';
        res += digit * pow(10, size - i - 1);
    }

    return res;
}

string to_string_own(ll n) {
    string res = "";
    while (n) {
        char digit = (char) (n % 10) + '0';
        res = digit + res;
        n /= 10;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    cout << to_string_own(n) << endl;

    return 0;
}
