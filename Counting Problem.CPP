#include<iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, p = 1e9 + 7;

ll fact[N], infact[N];

ll qmi(ll a, ll b, int p)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }

    return res;
}

ll C(int a, int b, int p)
{
    return fact[a] * infact[b] % p * infact[a - b] % p;
}

int main()
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i ++ )
    {
        fact[i] = fact[i - 1] * i % p;
        infact[i] = infact[i - 1] * qmi(i, p - 2, p) % p;
    }

    int t;
    cin >> t;
    while(t -- )
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll s = 0;
        for(int x = 1; x <= n; x ++ )
            if(x <= k)
                s = (s + C(n, x, p) * (qmi(m - k + 1, x, p) - qmi(m - k, x, p) + p) % p * qmi(k - 1, n - x, p)) % p;
            else
                s = (s + C(n, x, p) * (qmi(m - k + 1, x, p)
                 - (qmi(m - k, k, p) * qmi(m - k + 1, x - k, p)) % p
                  + p) % p * qmi(k - 1, n - x, p)) % p;
            
        cout << s << endl;
    }

    return 0;
}
