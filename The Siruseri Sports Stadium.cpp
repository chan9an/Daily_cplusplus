//https://www.codechef.com/IARCSJUD/problems/STADIUM?tab=statement
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n;
	cin>>n;
	multiset<pair<ll,ll>> nums;
	for(ll i=0;i<n;i++){
		ll s,d;
		cin>>s>>d;
		nums.insert(make_pair(d+s,s));
	}
	ll m=0;
	ll l=0;
	for(const auto&it:nums){
		if(it.second>l){
			m++;
			l=it.first;
		}
	}
	cout << m << endl;
}
