#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <vector>
int main() {
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int sum=n1+n2+n3;
	int a[sum];
	vector<int> newvec;
	for(int i=0;i<sum;i++){
	    cin>>a[i];
	}
	sort(a,a+sum);
	for(int i=0;i<sum;i++){
	    if(a[i] == a[i+1] && a[i] == a[i+2])
		{
			newvec.push_back(a[i]);
			i += 2;
		}
		else if(a[i] == a[i+1])
		{
			newvec.push_back(a[i]);
			i++;
		}
	}
	cout<<newvec.size()<<endl;
	for(int i = 0; i < newvec.size(); i++)
	{
		cout<<newvec[i]<<endl;
	}
	return 0;
}
