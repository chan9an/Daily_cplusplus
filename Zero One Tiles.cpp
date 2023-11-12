#include <iostream>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int N;
    std::cin >> N;
    
    int s[N+1];
    s[0] = 1;
    s[1] = 1;
    for (int i = 2; i <= N; i++) {
        s[i] = (s[i-1] + s[i-2]) % 15746;
    }
    
    std::cout << s[N] % 15746;
    
	return 0;
}
