#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

#define PB push_back
#define MP make_pair
#define F  first
#define S  second

typedef long long ll;
typedef std::pair<int, int> pi;
typedef std::vector<int> vi;
typedef std::vector<pi> vii;
typedef std::vector<vi> vvi;

void solve(int n) {
    vector<string> res;

    queue<string> q;
    q.emplace("0");
    q.emplace("1");

    while (true) {
        string s = q.front();
        q.pop();

        if (s.size() >= n)
            break;

        res.push_back(s);

        q.push(s + "0");
        q.push(s + "1");
    }

    FOR(i, 0, res.size()) cout << res[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve(5);
    return 0;
}
