//https://www.codechef.com/IARCSJUD/problems/LEADGAME?tab=solution
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
    map<int,int> m;
    int s1=0,t1=0,max1=0,max2=0,a1=0,a2=0;
    for(int j=0;j<n;j++){
        cin>>a1>>a2;
		s1 += a1;
		t1 += a2;
        if(s1>=t1){
         max1=max(max1,s1-t1);	
        }
        else{
             max2=max(max2,t1-s1);	
        }
    }
	
    if(max1>=max2) cout<<1<<" "<<max1<<endl;
    else cout<<2<<" "<<max2<<endl;
	return 0;
}
