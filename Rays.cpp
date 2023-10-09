/*
You are given a grid of size N x M consisting of '.' (empty), 'W' (white) or 'B' (black) cells. We follow the convention that the top left corner is the position (1,1) and bottom right corner is (N,M).

From every '.' cell (i, j), a ray is shot towards the right. If the ray reaches a 'B' cell, it loses it's strength fully and stops there. When a ray reaches a 'W' cell, it's strength drops drastically so that the ray stops when it reaches a second 'W' cell. That is, if there is no 'B' cell in between, a ray can cross at most one 'W' cell, and it will stop when it reaches the second 'W' cell. It passes unchanged through any '.' cell. If it reaches a boundary cell (ie. (i,M), for some i), it stops there.

Let L(i, j) be length travelled by the ray starting from the cell (i, j). If (i,j) is 'W' or 'B', no ray starts from here, and hence L(i,j) is defined to be 0. If a ray starts from (i,j) and stops at (i,k), then the distance travelled by this ray is k-j+1. i.e, inclusive of both starting and ending cells.

For the given grid your task is to find the sum of L(i, j) over all 1 <= i <= N and 1 <= j <= M.

The description of the grid is given as follows: In addition to N and M, you are given the number of 'W' cells (w) and the number of 'B' cells (b) and you are given the locations of these w + b cells. (The other cells contain '.')

###Constraints:

For all testcases,

1 <= N, M <= 10^6.
0 <= w,b <= 10^5
Subtask 1: 15%

It is guaranteed that 1 <= N,M <= 500

Subtask 2: 25%

It is guaranteed that 1 <= N,M <= 2000

Subtask 3: 60%

No additional guarantees.

###Input format:

There is only one line of input which contains 4 + 2w + 2b space separated integers. The first four integers are N, M, w and b.
The next 2*w integers denote the cells which contains a 'W': x_1 y_1 x_2 y_2 .. x_w y_w. These denote that (x_i,y_i) contains 'W'.
The next 2*b integers denote the cells which contains a 'B': x_1 y_1 x_2 y_2 .. x_b y_b. These denote that (x_i,y_i) contains 'B'.
The cells which are not in the input have to be assumed to be '.'
###Output format: Output a single integer which is the sum of L(i,j) over all 1 <= i <= N and 1 <= j <= M.

###Sample Input 1: 4 4 5 2 1 3 2 1 3 2 3 3 4 3 1 4 2 3

###Sample Output 1: 22

###Explanation:

The grid is:

. . W B
W . B .
. W W .
. . W .
L(i,j) for each cell is:

4 3 0 0
0 2 0 1
3 0 0 1
4 3 0 1
Therefore, the total is 22.

###Note: As the answer might be large, please use 64 bit integers (long long int in C/C++ and long in Java) instead of 32 bit int.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;

#define int int64_t

vector<pair<int, pair<int, bool>>>  block;

bool comp(pair<int, pair<int, bool>> p1, pair<int, pair<int, bool>> p2)
{
	if (p1.first == p2.first)
		return p1.second.first < p2.second.first;

	return p1.first < p2.first;
}

int com(int up)
{
	return ((up * (up + 1)) / 2);
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

	int n, m, w, b;
	cin >> n >> m >> w >> b;

	for (int i = 0; i < w; ++i)
	{
		int p1, p2;
		cin >> p1 >> p2;
		block.push_back(make_pair(p1, make_pair(p2, 0)));
	}

	for (int i = 0; i < b; ++i)
	{
		int p1, p2;
		cin >> p1 >> p2;
		block.push_back(make_pair(p1, make_pair(p2, 1)));
	}

	sort(block.begin(), block.end(), comp);

	int j = 0, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int oprev = -1;
		pair<int, bool> prev = { 0,1 };

		for (; j < block.size(); ++j)
		{
			if (block[j].first != i)
				break;

			if (block[j].second.second)//? --//will end at j//--> ? --//will end at j//--> b <---- j
			{
				if (prev.second)//? ----> b --//will end at j//--> b <---- j 
				{
					int up = prev.first == 0 ? block[j].second.first : (block[j].second.first - prev.first);
					ans += com(up);
					ans--;//no ray will come out of current square
				}
				else//? --//will end at j//--> w --//will end at j//--> b <---- j
				{                                                                 
					int up = oprev == -1 ? block[j].second.first : (block[j].second.first - oprev);
					ans += com(up);
					ans -= (block[j].second.first - prev.first) + 1;//delete path of the white square in between as no ray will come out of it
					ans--;//no ray will come out of current square
				}
			}
			else if (prev.second == 0 && prev.first != 0)//? --//will end at j//--> w -----> w <---- j
			{   
				int up = oprev == -1 ? (block[j].second.first) : (block[j].second.first - oprev);
				ans += com(up);
				up = ((block[j].second.first - prev.first) + 1);
				ans -= com(up);//delete paths of rays starting in front of prev square as they will not end at current square
			}

			oprev = prev.first;
			prev = make_pair(block[j].second.first, block[j].second.second);
		}

		//consider rays that reached the end
		if (prev.second)//b.w.b..
		{
			int up = m - prev.first;
			ans += com(up);
		}
		else//w.b.w.w. or ..w. or w.b.w
		{
			int up = 0;
			if (oprev == -1)//..w.
				up = m;
		
			else //w.b.w.w. or w.b.w
				up = (m - oprev);
			
			ans += com(up);
			ans -= ((m - prev.first) + 1);//delete path of the white square in between as no ray will come out of it
		}
	}

	cout << ans << endl;
	return 0;
}
