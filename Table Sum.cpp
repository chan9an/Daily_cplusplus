//https://www.codechef.com/INOIPRAC/problems/INOI1202?tab=statement
#include <bits/stdc++.h>



using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define endl "\n"

const int N = 2e5+20;
const ll INF = 1e18+10;
const int mod = 1e8+10-10;

int a[N], b[N], preMax[N], postMax[N];

void solve()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    int ans = 0;
    for(int i=1; i<=n; i++){
        b[i] = a[i]+i;
        ans = max(b[i], ans);
    }

    preMax[1] = b[1];
    for(int i=2; i<=n; i++)
        preMax[i] = max(preMax[i-1], b[i]);
    postMax[n] = b[n];
    for(int i=n-1; i>0; i--)
        postMax[i] = max(postMax[i+1], b[i]);

    int mx=0;

    cout << ans << " ";

    for(int i=1; i<n; i++){
        cout << max(preMax[n-i]+i, postMax[n-(i-1)]-(n-i)) << " ";
    }

    cout << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t;
    // cin >> t;
    t=1;
    
    for(int i=1; i<=t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }

}
