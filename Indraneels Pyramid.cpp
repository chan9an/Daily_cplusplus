#include <iostream>
#include <set>
#include <algorithm>

int main() {
	// your code goes here
	int M;
	std::cin >> M;
	
	std::multiset<int> v;
	
	for (int i = 0; i < M; i++)
	{
	    int x, y;
	    std::cin >> x >> y;
	    v.insert(std::min(x, y));
	}
	int res = 0;
	
	for (int x : v)
	{
	    if (x > res)
	    {
	        res++;
	    }
	}
	
	std::cout << res;
	
	return 0;
}
