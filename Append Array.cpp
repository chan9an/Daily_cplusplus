#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

const int N = 2000500;
const int mod = 998244353;

typedef long long ll;

int mnp[N], F[N], last[N][30];

int main() {

    for (int i = 2; i < N; i++) if (mnp[i] == 0) {
        mnp[i] = i;
        for (int j = i + i; j < N; j += i) if (mnp[j] == 0) mnp[j] = i;
    }
    for (int i = 2; i < N; i++) {
        int d = i;
        while (d > 1) d /= mnp[d], F[i]++;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 30; j++) last[i][j] = last[i - 1][j];
        last[i][F[i]] = i;
        for (int j = 1; j < 30; j++) last[i][j] = max(last[i][j], last[i][j - 1]);
    }
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        ll s = 0;
        int mx = 0, mx1 = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            s += a;
            if (F[a] > mx) mx1 = mx, mx = F[a];
            else if (F[a] > mx1) mx1 = F[a];
        }
        ll ans = 0;
        for (int d = 22; d >= 0; d--) for (int d1 = d; d1 >= 0; d1--) {
            int mxx = mx, mxx1 = mx1;
            if (d > mxx) mxx1 = mxx, mxx = d;
            else if (d > mxx1) mxx1 = d;
            if (d1 > mxx) mxx1 = mxx, mxx = d1;
            else if (d1 > mxx1) mxx1 = d1;
            ans = max(ans, 1ll * last[m][d] + 1ll * last[m][d1] * (k - 1) + s - mxx - mxx1);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
