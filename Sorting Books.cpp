//https://www.codechef.com/IARCSJUD/problems/BOOKSORT
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n; 
	cin >> n;
	int data[n] = {0};
	int pos = 0;
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		if (x > data[pos]) {
		    pos++;
			data[pos] = x;
		}
		else {
		    int temp = 0;
		    while(x > data[temp]) 
		        temp++;
		    data[temp] = x;
		}
	}
	cout << (n - pos) << endl;
	return 0;
}
