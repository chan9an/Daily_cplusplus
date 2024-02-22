#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	 int n,m,x,y,l;
	 cin>>n>>m>>x>>y>>l;
	 long long int r=0,c=0;
	 r+=(x-1)/l+(n-x)/l+1;
	 c+=(y-1)/l+(m-y)/l+1;
	 cout<<r*c<<endl;
	}
}
