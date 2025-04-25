#include <iostream>
#include <sstream>
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
Nam Lan Phi

output:
Lan Nam Phi
Lan Phi Nam
Nam Lan Phi
Nam Phi Lan
Phi Nam Lan
Phi Lan Nam
*/

int n, ok, X[100];

void init() { FOR(i, 1, n) X[i] = i; }

void gen() {
    int i = n - 1;
    while (i >= 1 && X[i] > X[i + 1])
        i--;

    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j >= 1 && X[i] > X[j])
            --j;

        swap(X[i], X[j]);
        reverse(X + i + 1, X + n + 1);
    }
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
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);
        vector<string> words;

        stringstream ss(s);
        string word;
        while (ss >> word)
            words.push_back(word);

        sort(words.begin(), words.end());
        init();
        ok = 1;
        while (ok) {
            for (int i = 1; i <= n; i++)
                cout << words[X[i] - 1] << " ";

            cout << endl;
            gen();
        }
    }

    return 0;
}
