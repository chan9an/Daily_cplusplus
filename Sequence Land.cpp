#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 310;
vector<int> a[N];
vector<bool> visited(N, false);

bool is_neigh(int k, int x, int y) {
    int ans = 0;
    int i = 0, j = 0;
    
    while (i < a[x].size() && j < a[y].size()) {
        if (a[x][i] == a[y][j]) {
            ans++;
            i++;
            j++;
        } else if (a[x][i] < a[y][j]) {
            i++;
        } else {
            j++;
        }
    }

    return ans >= k;
}

int bfs(int n, int k) {
    int ans = 1;

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (!visited[i] && is_neigh(k, v, i)) {
                ans++;
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        a[i].resize(len);
        for (int j = 0; j < len; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }

    cout << bfs(n, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}
