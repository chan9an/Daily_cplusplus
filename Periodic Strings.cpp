//https://www.codechef.com/INOIPRAC/problems/INOI1502?tab=statement
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, mod;
    cin >> n >> mod;
    long long int result = 0;
    vector<int64_t> dp = {1}; // dp[i] represents 2^i % mod

    // Precompute powers of 2 modulo mod
    for (int i = 0; i < n; i++) {
        dp.push_back((dp[i] * 2) % mod);
    }

    // Calculate the number of non-periodic strings
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            result += dp[i];
            result %= mod;
            for (int j = i * 2; j <= n; j += i) {
                dp[j] = ((dp[j] - dp[i]) + mod) % mod;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
