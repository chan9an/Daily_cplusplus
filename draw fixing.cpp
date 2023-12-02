#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n;
	cin>>n;
	vector<pair<ll,ll>> s(n);
	vector<pair<ll,ll>> na(n);
	for(ll i=0;i<n;i++){
		ll num;
		cin>>num;
		s[i]=make_pair(num,i);
	}
	for(ll i=0;i<n;i++){
		ll num;
		cin>>num;
		na[i]=make_pair(num,i);
	}
	sort(s.begin(),s.end());
	sort(na.begin(),na.end());
	ll left=0;
	ll right1=0;
	ll right2=n-1;
	ll count=0;
	vector<ll> ans(n);
	while(right1<=right2){
		if(s[left].first>na[right1].first){
			ans[s[left].second]=na[right1].second+1;
			count++;
			right1++;
		}else{
			ans[s[left].second]=na[right2].second+1;
			right2--;
		}
		left++;
	}
	cout << count << endl;
	for(ll i=0;i<n;i++){
		cout << ans[i] << endl;
	}
	return 0;
}
