#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define dd long double
#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<ll,ll>
#define pdd pair<dd,dd>
#define fst first
#define snd second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<ll,        // key
             null_type,  // value
             less<ll>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;
/*
  How to use ordered_set:
  ordered_set X;
  X.insert(1);
  X.erase(1);
  X.find_by_order(1); // This gives an iterator.
  X.order_of_key(-5); // Lower bound, 0 based position.
 */

const int talla=2e5;
const double pi=3.141592653589793;

void solve(){
   int n;cin>>n;
   vector<int>v(n+1,0);
   int p1,p3;
   for(int i=1;i<=n;i++){
      cin>>v[i];
      if(v[i]==1)p1=i;
      if(v[i]==3)p3=i;
   }
   if(n==1 or n==2){
      cout<<-1;
      return;
   }
   swap(v[p1],v[p3]);
   for(int i=1;i<=n;i++){
      cout<<v[i]<<" ";
   }

}

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   cout.setf(ios::fixed);cout.precision(12);
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int t;cin>>t;
   while(t--){
      solve();
      cout<<"\n";
   }
   return 0;
}
