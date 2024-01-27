#include<bits/stdc++.h>
using namespace std;

int dp[200001][2][2];
string a;
int n;
const int mod=1e9+7;
int make(int i, int flag, int last)
{
    if (i == n)
    {
        if (flag == 1)
        {
            return last == 1;
        }
        else
        {
            return last == 0;
        }
    }
    if (dp[i][flag][last] == -1)
    {
        if (flag == 0)
        {
            if (a[i] == 'b') {
                if (last == 0)
                    dp[i][flag][last] = (make(i + 1, 0, last) + make(i + 1, 1, 1)) % mod;
                else
                {
                    dp[i][flag][last] = (make(i + 1, 0, last) ) % mod;
                }
            }
            else
            {
                dp[i][flag][last] = (make(i + 1, 0, 0) + make(i + 1, 0, last)) % mod;

            }

        }
        else
        {
            if (last == 0)
            {
                if (a[i] == 'b')
                {
                    dp[i][flag][last] = (make(i + 1, 1, 1) + make(i + 1, 1, last)) % mod;

                }
                else
                {
                    dp[i][flag][last] = make(i + 1, 1, 0);
                }
            }
            else
            {
                if (a[i] == 'a')
                {
                    dp[i][flag][last] = (make(i + 1, 1, 0) + make(i + 1, 1, last)) % mod;

                }
                else
                {
                    dp[i][flag][last] = make(i + 1, 1, 1);
                }

            }


        }

    }
    return dp[i][flag][last];
}
void solve()
{

    cin >> a;
    n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << (make(0, 0, 1)) % mod << endl;












}


int main() {
    int t;

    cin >> t;









    while (t--)
    {   // cout << "Case #" << i + 1 << ": ";
        solve();
   
    }
    
    return 0;
}
