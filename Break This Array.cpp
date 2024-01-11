#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

template<int MD> struct mi {
   int v;
   explicit operator int() const { return v; }
   mi(long long _v = 0) {
       v = (-MD <= _v && _v < MD) ? _v : _v % MD;
       if (v < 0) v += MD;
   }
 
   mi &operator+=(const mi &o) { if ((v += o.v) >= MD) v -= MD; return *this; }
   mi &operator-=(const mi &o) { if ((v -= o.v) < 0) v += MD; return *this; }
   mi &operator*=(const mi &o) { v = 1LL * v * o.v % MD; return *this; }
   mi &operator/=(const mi &o) { return (*this) *= inv(o); }
 
   friend mi operator+(mi a, const mi &b) { return a += b; }
   friend mi operator-(mi a, const mi &b) { return a -= b; }
   friend mi operator*(mi a, const mi &b) { return a *= b; }
   friend mi operator/(mi a, const mi &b) { return a /= b; }
 
   friend mi inv(const mi &m) { return binpow(m, MD - 2); }
   friend mi binpow(mi b, long long e) {
       mi ret = 1;
       for (; e; e >>= 1, b *= b) if (e & 1) ret *= b;
       return ret;
   }
 
   friend bool operator==(const mi &a, const mi &b) { return a.v == b.v; }
   friend bool operator!=(const mi &a, const mi &b) { return !(a == b); }
   friend bool operator<(const mi &a, const mi &b) { return a.v < b.v; }
 
   friend istream &operator>>(istream &i, mi &m) { long long x; i >> x; m.v = x; return i; }
   friend ostream &operator<<(ostream &o, const mi &m) { o << m.v; return o; }
};

const int mod = 1e9 + 7;
using Mint = mi<mod>;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    string s;
    cin >> s;

    vector<vector<Mint>> prob(n + 1, vector<Mint> (n + 1));
    vector<Mint> iv(n + 1);
    for(int i = 1; i <= n; i++)
        iv[i] = (Mint) 1 / i;

    prob[1][n] = 1;

    for(int step = 0; step < k; step++) {
        vector<vector<Mint>> dp(n + 1, vector<Mint> (n + 1));
        if(s[step] == 'L') {
            for(int i = 1; i <= n; i++) {
                Mint sum = 0;
                for(int j = n; j >= i; j--) {
                    dp[i][j] = sum;
                    if(i == j)
                        dp[i][j] += prob[i][j];

                    sum += prob[i][j] * iv[j - i];
                }
            }
        }
        else {
            for(int j = 1; j <= n; j++) {
                Mint sum = 0;
                for(int i = 1; i <= j; i++) {
                    dp[i][j] = sum;
                    if(i == j)
                        dp[i][j] += prob[i][j];

                    sum += prob[i][j] * iv[j - i];
                }
            }
        }

        swap(prob, dp);
    }

    Mint ans = 0;
    for(int i = 1; i <= n; i++) {
        Mint sum = 0;
        for(int j = i; j <= n; j++) {
            sum += a[j];
            ans += sum * prob[i][j];
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}
