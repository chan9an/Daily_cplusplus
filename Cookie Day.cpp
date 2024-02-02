#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define rloop(i, b, a) for (ll i = b; i >= a; i--)
// Author - Anshul Pandey
using namespace std;
void print(vi vec)
{
    int a = 0, b = vec.size();
    loop(i, a, b)
        cout << vec[i] << ' ';
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >>t;
    while(t--){
        ll n , k ;
        cin >> n >> k;
        ll mini = LLONG_MAX;
        bool chk = false;
        for(ll i = 0 ;i < n ;i++){
            ll a;
            cin >> a;
            if(a/k >= 1){
                chk = true;
                mini = min(a%k,mini);
            }
        }
        if(chk == true)
            cout << mini << "\n";
        else{
            cout << -1 << "\n";
        }
    }
}
