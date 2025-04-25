#include <iostream>
using namespace std;

// Factorization
vector<int> factorize(int n) {
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
        primes.push_back(n);

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> primes = factorize(n);
    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";

    return 0;
}
