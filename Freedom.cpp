#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define LL_MAX 1e18 + 1
#define LL_MIN -1e18
const int mod = 1e9 + 7;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;
void solve()
{
    ll n, cnt = 0;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
            mp[a[i]]--;
        if ((a[i] - 3) <= 0)
        {
            continue;
        }
        if ((a[i] % (a[i] - 3)) == 0)
        {
            ll di = a[i] / (a[i] - 3);
            cnt += mp[di];
        }
    }
    cout << cnt;
}

int main()
{
    // fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
