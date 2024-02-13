#include <iostream>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
// #include <list>
#include <queue>
#include <deque>
#include <stack>
// #include <time.h>
// #include <bitset>
// #include <fstream>
// #include <bit>

// #include <bits/stdc++.h>
using namespace std;
#define MYMAXVAL 300002
#define MAXNUM 998244353
#define PPPP 1000000007

#define stt(n) {cout << ((n) ? "YES" : "NO") << endl; return;}
#define int long long
#define ull unsigned long long
#define pb push_back
#define vi vector<long long>
#define vb vector<bool>
#define vvi vector<vector<long long>>
#define vpi vector<pair<long long, long long>>
#define mp make_pair
#define mne min_element
#define mxe max_element
#define all(var) var.begin(), var.end()
#define rall(var) var.rbegin(), var.rend()
#define rep(i,a,n) for (int i = (a); i < (n); i++)
#define repneg(i, a, n) for (int i = (a); i >= (n); i--)
#define gib(n) cout << n << endl;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define getvl(v) for (auto &x : v) cin >> x;
#define gibvl(v) {for (auto x : v) cout << x << ' '; cout << endl;}

/**********/

void solve () {
        int c,y;
        cin >> c >> y;
        gib(__gcd(c,y));
}

/***********/

int32_t main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests = 1;
    cin >> tests;
    while (tests--)
        solve();
    return 0;
}
