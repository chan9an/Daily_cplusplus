#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;

int T;
int n, m;
int a[Maxn];

int Solve()
{
    int res = n;
    set <int> S;
    S.insert(a[0]);
    for (int i = 1; i < n; i++) {
        int cand = i;
        auto it = S.lower_bound(a[i]);
        if (it != S.end() && *it == a[i]) {
            res = min(res, cand);
            continue;
        }
        if (it != S.end())
           cand += 2 * (*it - 1 - a[i]);
        else cand += 2 * (m + *S.begin() - 1 - a[i]);
        res = min(res, cand);
        it = S.upper_bound(a[i]);
        cand = i;
        if (it != S.begin()) {
            it--;
            cand += 2 * (a[i] - *it);
        } else cand += 2 * (m + a[i] - *S.rbegin());
        res = min(res, cand);
        S.insert(a[i]);
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%d\n", n + Solve());
    }
    return 0;
}
