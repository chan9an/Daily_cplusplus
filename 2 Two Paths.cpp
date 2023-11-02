//https://www.codechef.com/INOIPRAC/problems/TWOPATHS?tab=statement
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int arr[n][m], dp[n][m][k + 1], dp1[n][m][k + 1], pref[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) pref[i][j] = arr[i][j];
                else pref[i][j] = pref[i][j - 1] + arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int c = 0; c <= k; c++) {
                    dp[i][j][c] = pref[i][j];
                    if (!i) continue;
                    if (!j || !c) dp[i][j][c] += dp[i - 1][j][c];
                    else dp[i][j][c] += max(dp[i - 1][j][c], dp[i - 1][j - 1][c - 1]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int c = 0; c <= k; c++) {
                    dp1[i][j][c] = pref[i][j] - arr[i][j];
                    if (!i) continue;
                    if (!j || !c) dp1[i][j][c] += dp1[i - 1][j][c];
                    else dp1[i][j][c] += min(dp1[i - 1][j][c], dp1[i - 1][j - 1][c - 1]);
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = i + k + 1; j < m; j++) {
                ans = max(ans, dp[n - 1][j][k] - dp1[n - 1][i][k]);
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
