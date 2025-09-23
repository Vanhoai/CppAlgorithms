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

// use hoare
int partition(int a[], int L, int R) {
    int m = (L + R) >> 1;
    int p = a[m];

    int i = L, j = R;
    while (i < j) {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;

        if (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    return i;
}

void quick_sort(int a[], int L, int R) {
    if (L >= R)
        return;

    int pivot = partition(a, L, R);
    quick_sort(a, L, pivot - 1);
    quick_sort(a, pivot + 1, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    quick_sort(a, 0, n - 1);

    FOR(i, 0, n) cout << a[i] << " ";

    return 0;
}
