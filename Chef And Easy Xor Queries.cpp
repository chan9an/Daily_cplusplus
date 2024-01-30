#include <bits/stdc++.h>

using namespace std;

#define int long long

int block[350];

int Min(int a, int b)
{
    if (a > b) return b;
    return a;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, len = 350;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> mp[len];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % len == 0)
            x = 0;
        x = x ^ v[i];
        mp[i / len].push_back(x);
        block[i / len] = block[i / len] ^ v[i];
    }
    for (int i = 0; i < len; i++)
        sort(mp[i].begin(), mp[i].end());
    while (q--)
    {
        int ans = 0;
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 2)
        {
            a--;
            x = 0;
            for (int i = 0; i < a / len; i++)
            {
                ans += upper_bound(mp[i].begin(), mp[i].end(), x ^ b) - lower_bound(mp[i].begin(), mp[i].end(), x ^ b);
                x ^= block[i];
            }
            for (int j = len * (a / len); j <= a; j++)
            {
                x ^= v[j];
                if (x == b)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
        else
        {
            a--;
            int c = 0;
            mp[a / len].clear();
            v[a] = b;
            for (int i = len * (a / len); i < Min(n, len * (a / len + 1)); i++)
            {
                c ^= v[i];
                mp[a / len].push_back(c);
            }
            sort(mp[a / len].begin(), mp[a / len].end());
            block[a / len] = c;
        }
    }
}
