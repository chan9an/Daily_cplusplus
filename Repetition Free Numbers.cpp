#include <bits/stdc++.h>
using namespace std;


bool isFree(int n){
    unordered_set<int>s;
    while(n){
        int dig=n%10;
        if(dig==0||s.find(dig)!=s.end())
        return 0;
        
        else
        s.insert(dig);
        
        n/=10;
    }
    return 1;
}

int main() {
	// your code goes here
	int n;
	std::cin >> n;
	
	int rep_free = 0;
	while (n++ <= 987654321) {
	    if (isFree(n)) {
	        rep_free = n;
	        break;
	    }
	}
	
	std::cout << rep_free << '\n';
	
	return 0;
}
