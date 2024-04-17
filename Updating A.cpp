#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif

#define  IOS 	      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  ll  	      long long
#define  rep(i,a,b)   for(ll i = a ; i < b ; i ++)
#define  Rep(i,a,b)   for(ll i = a ; i >= b ; i --)
#define  fi  	      first
#define  se  	      second
#define  pb  	      push_back
#define  pf  	      push_front
#define  mk  	      make_pair
#define  vi  	      vector<ll>
#define  pi  	      pair<ll,ll>
#define  vp  	      vector<pi>
#define  vvp  	      vector<vp>
#define  vv  	      vector<vi>
#define  all(v)  	  v.begin(),v.end()
const ll MOD = 1000000007;
const ll INF = 3e18 + 5;

int main(){

    IOS;
    ll tc; cin>>tc;
    while(tc--){
        int n; cin >> n;
        vi v(n);
        rep(i, 0, n) cin >> v[i];
        ll sum = accumulate(all(v), 0LL);
        if(n <= 2){
            if(n == 2) sum = abs(sum);
            cout << sum << '\n';
            continue;
        }
        vi pre(n), suf(n);
        rep(i, 0, n){
            pre[i] += v[i];
            if(i  - 1 >= 0){
                pre[i] += pre[i - 1];
            }
        }
        multiset<ll> l, r;
        Rep(i, n - 1, 0){
            suf[i] += v[i];
            if(i + 1 < n){
                suf[i] += suf[i + 1];
            }
            r.insert(suf[i]);
        }
        ll ans = abs(sum);
        r.erase(r.find(suf[0]));
        r.erase(r.find(suf[1]));
        ans = max(abs(sum - *r.rbegin()) + *r.rbegin(), ans);
        l.insert(pre[0]);
        rep(i, 2, n){
            r.erase(r.find(suf[i]));
            if(!r.empty() && !l.empty()){
                ll L = *l.rbegin();
                ll R = *r.rbegin();
                ll res = abs(sum - (L + R)) + L + R;
                res = max(abs(sum - R) + R, res);
                res = max(abs(sum - L) + L, res);
                ans = max(ans, res);
            }
            if(i - 1 <= n - 3){
                l.insert(pre[i - 1]);
            }
        }
        ans = max(ans, abs(sum - *l.rbegin()) + *l.rbegin());
        cout << ans << '\n';
    }

}
