#include <bits/stdc++.h>

using namespace std;


// Solved: Space optimization can be done but isn't necessary.

int next(vector<int> &count)
{
    int index = 0, value = INT_MAX;
    for(int i = 1; i < count.size(); ++i)
        (count[i] and value > count[i])? value = count[i], index = i: value;
    return index;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> count(n + 1, 0);
    vector< vector<bool> > pairs(n + 1, vector<bool>(n + 1, false));
    for(int i = 0; i < m; ++i)
    {
        int j, k;
        cin >> j >> k;
        
        pairs[j][k] = pairs[k][j] = true;
        count[j]++, count[k]++;
    }

    int i;
    while(count[i = next(count)] < k and count[i])
    {
        count[i] = 0;
        for(int j = 1; j <= n; ++j)
            (pairs[i][j])? pairs[i][j] = pairs[j][i] = false, count[j]--: pairs[i][j];
    }

    int ans = 0;
    for(auto x: count) (x)? ans++: ans;

    (ans)? cout << "YES" << "\n" << ans << "\n": cout << "NO" << "\n";
}
