#include <bits/stdc++.h>



#define int long long
using namespace std;

int32_t main() 
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i : v)
        cin>>i;
    
    v.insert(v.begin(), 0);
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=k; i++)
        dp[0][i] = 0;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=2)
                for(int k=i-2; k>=0; k--)
                    dp[i][j] = max(dp[i][j], dp[k][j-2] + v[i]-v[k+1]);
        }
    cout<<dp[n][k]<<"\n";
	return 0;
}
