#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<n;i++)
#define foa(e, v) for(auto&& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b; a --; b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    string s(n, '.');
    int cnt = 0;
    auto dfs = [&](auto dfs, int now, int p) -> void {
        foa(e, v[now]) {
            if(e == p) continue;
            dfs(dfs, e, now);
        }
        if(cnt > 0) {
            s[now] = 'B';
            cnt --;
        } else {
            s[now] = 'R';
            cnt ++;
        }
    };
    dfs(dfs, 0, -1);
    cout << s << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}
