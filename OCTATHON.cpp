//https://www.codechef.com/problems/OCTATHON?tab=statement
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int x;
	cin>>x;
	if(x<3){
	    cout<<"GOLD";
	}
	else if(x>=3 && x<6){
	    cout<<"SILVER";
	}
	else{
	    cout<<"BRONZE";
	}
	return 0;
}