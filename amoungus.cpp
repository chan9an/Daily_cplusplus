#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long int
#define ull unsigned long long
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define fo(i, init, n) for (int i = init; i < n; i++)
#define fr(i, n, e) for (int i = n; i > e; i--)
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vi>
#define vvl vector<vl>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define si set<int>
#define msi multiset<int>
#define sl set<ll>
#define usi unordered_set<int>
#define usl unorderd_set<ll>
#define msl multiset<ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define it(n) for (auto &el : n)
#define endl "\n"
#define ft first
#define sd second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define SQ(a) (a) * (a)
const int N = 5e5 + 5;
int col[N];
bool dfs(int i, vector<pi> adj[], vi &vis, int &cnt1, int &cnt2)
{
    vis[i] = 1;
    if (col[i] == 1)
    {
        cnt1++;
    }
    else
    {
        cnt2++;
    }
    for (auto &child : adj[i])
    {
        if (vis[child.first] == 0)
        {
            if (child.second == 1)
            {
                if (col[i] == 1)
                {
                    col[child.first] = 2;
                }
                else
                {
                    col[child.first] = 1;
                }
            }
            else
            {
                if (col[i] == 1)
                {
                    col[child.first] = 1;
                }
                else
                {
                    col[child.first] = 2;
                }
            }
            if (!dfs(child.first, adj, vis, cnt1, cnt2))
            {
                return false;
            }
        }
        else
        {
            if (child.second == 1)
            {
                if (col[child.first] == col[i])
                {
                    return false;
                }
            }
            else
            {
                if (col[child.first] != col[i])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    int type, a, b;
    vector<pi> adj[n];
    for (int i = 0; i < q; i++)
    {
        cin >> type >> a >> b;
        a--;
        b--;
        adj[a].push_back({b, type});
        adj[b].push_back({a, type});
    }
    vi vis(n, 0);
    bool flag = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            col[i] = 1;
            int cnt1 = 0, cnt2 = 0;
            flag &= dfs(i, adj, vis, cnt1, cnt2);
            if (!flag)
            {
                break;
            }
            ans += max(cnt1, cnt2);
        }
    }
    if (!flag)
    {
        cout << -1 << "\n";
        return;
    }
    cout << ans << "\n";
}
int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
