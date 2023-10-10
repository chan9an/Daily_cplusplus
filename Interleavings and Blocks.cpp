/*
https://www.codechef.com/ZCOPRAC/problems/ZCO20002?tab=statement
*/
#include <bits/stdc++.h>
using namespace std;
int const MAXN = 101;
int dp[MAXN][MAXN][2*MAXN][2];
int a[MAXN], b[MAXN];
int n, m, k;
int const mod = 1e8+7;
int solve(int i, int j, int blocks, int last){
    if(i == n && j == m){
        if(blocks == k)
            return 1;
        else
            return 0;
    }
    if(i > n || j > m || blocks > k)
        return 0;
    if(dp[i][j][blocks][last] != -1)
        return dp[i][j][blocks][last];
    long long ans = 0;
    if(last == 0){
        if(a[i] == a[i-1])
            ans += solve(i+1,j,blocks,0);
        else
            ans += solve(i+1,j,blocks+1,0);
        if(b[j] == a[i-1])
            ans += solve(i,j+1,blocks,1);
        else
            ans += solve(i,j+1,blocks+1,1);
    }else{
        if(b[j] == b[j-1])
            ans += solve(i,j+1,blocks,1);
        else
            ans += solve(i,j+1,blocks+1,1);
        if(a[i] == b[j-1])
            ans += solve(i+1,j, blocks,0);
        else
            ans += solve(i+1,j,blocks+1,0);
    }
    ans %= mod;
    dp[i][j][blocks][last] = ans;
    return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int j = 0; j < m; j++)
            cin >> b[j];
        memset(dp,-1,sizeof dp);
        cout << (solve(1,0,1,0) + solve(0,1,1,1))%mod << '\n';
    }
   return 0;
}
