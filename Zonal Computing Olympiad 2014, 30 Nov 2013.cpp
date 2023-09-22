/*
In IPL 2025, the amount that each player is paid varies from match to match. The match fee depends on the quality of opposition, the venue etc.


The match fees for each match in the new season have been announced in advance. Each team has to enforce a mandatory rotation policy so that no player ever plays three matches in a row during the season.


Nikhil is the captain and chooses the team for each match. He wants to allocate a playing schedule for himself to maximize his earnings through match fees during the season.


Input format
Line 1: A single integer N, the number of games in the IPL season.

Line 2: N non-negative integers, where the integer in position i represents the fee for match i.


Output format
The output consists of a single non-negative integer, the maximum amount of money that Nikhil can earn during this IPL season.

Test data
There is only one subtask worth 100 marks. In all inputs:

• 1 ≤ N ≤ 2×105

• The fee for each match is between 0 and 104, inclusive.


Live evaluation data
There are 12 test inputs on the server during the exam.

Sample 1:
Input
Output
5 
10 3 5 7 3 
23
Explanation:
Explanation: 10+3+7+3

Sample 2:
Input
Output
8
3 2 3 2 3 5 1 3
17
Explanation:
Explanation: 3+3+3+5+3
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {
	
	int N ;
	cin>>N ;
	vector<int>A(N);

	for( auto &x : A )
	cin>>x ;
	
	int sum = accumulate( A.begin() , A.end() , 0LL );
	
	deque< int > q ;
	
	auto dis = [&]( int a, int b)->int
	{
	  return b-a ;  
	};
	
	int k = 3 ;
	int t[N] ;
	
	for( int i = 0 ; i < N ; i++ )
	{
	    while(q.size() && dis(q.front(),i) > k )q.pop_front();
	    
	    t[i] = A[i] ;
	    
	    if( i >= k )
	    t[i] += t[q.front()];
	    
	    while( q.size() && t[q.back()] > t[i] ) q.pop_back();
	    
	    q.push_back(i);
	}
	int mn = INT_MAX;
	for( int i = N-1 ; i > N-k-1 ; i-- )
	mn = min( mn , t[i] );
	
	cout<<sum-mn<<endl;
	return 0;
}
