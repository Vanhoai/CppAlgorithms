#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

const int maxn = 1000000 + 5;   // 10^6 + 5
bool is_prime[maxn];

void sieve(int n) {
    // make all numbers from 2 to n prime
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;

    // can be use memset instead of loop
    for (int i = 2; i + i <= n; i++) {
        if (is_prime[i]) {
            for (int k = i * i; k <= n; k += i)
                is_prime[k] = false;
        }
    }
}

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
    SETUP;

    int n;
    cin >> n;

    vector primes = factorize(n);
    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";

    return 0;
}