//
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int t,arr[N],s[N],i,j,k,n,ind;
main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for( i = 1; i <= n; i++){
		cin >> arr[i];
		s[ i ] = s[i-1] + arr[ i ];
	}
	j=t=s[k];
	ind=k;
	for ( i = k+1; i<=n; i++){
		if(t+arr[i] < s[i]-s[i-k])
		t=s[i]-s[i-k];
		else t+=arr[i];
		j = max(j,t);
	}
	cout << j;
}
