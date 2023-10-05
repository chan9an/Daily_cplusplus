/*
Zonal Computing Olympiad 2013, 10 Nov 2012

Spaceman Spiff has crash landed on Planet Quorg. He has to reach his ship quickly. But the evil Yukbarfs have stolen many Death Ray Blasters and have placed them along the way. You'll have to help him out!


Spaceman Spiff is initially at the top left corner (1,1) of a rectangular N × M grid . He needs to reach the bottom right corner (N,M). He can only move down or right. He moves at the speed of 1 cell per second. He has to move every second—that is, he cannot stop and wait at any cell.


There are K special cells that contain the Death Ray Blasters planted by the Yukbarfs. Each Blaster has a starting time t and a frequency f. It first fires at time t seconds, followed by another round at time t+f seconds, then at time t+2f seconds …. When a Blaster fires, it simultaneously emits four pulses, one in each of the four directions: up, down, left and right. The pulses travel at 1 cell per second.
Suppose a blaster is located at (x,y) with starting time t and frequency f. At time t seconds, it shoots its first set of pulses. The pulse travelling upwards will be at the cell (x,y-s) at time t+s seconds. At this time, the pulse travelling left will be at cell (x-s,y), the pulse travelling right will be at cell (x+s,y) and the pulse travelling down will be at cell (x,y+s). It will fire next at time t+f seconds. If a pulse crosses an edge of the grid, it disappears. Pulses do not affect each other if they meet. They continue along their original path. At any time, if Spaceman Spiff and a pulse are in the same cell, he dies. That is the only way pulses interact with Spaceman Spiff. Spaceman Spiff can also never be on a cell which has a blaster. Given these, you should find the least time (in seconds) in which Spaceman Spiff can reach his ship safely.


As an example consider a 4×4 grid that has only one Blaster, at (3,2), with starting time 1 and frequency 3. In the grids below, S denotes Spaceman Spiff, B denotes the blaster and P denotes a pulse. The sequence of grids describes a successful attempt to reach his ship that takes 6 seconds.

   t=0                t=1                t=2                t=3  
S  .  .  .         .  S  .  .         .  .  S  .         .  P  .  S
.  .  .  .         .  .  .  .         .  P  .  .         .  .  .  .
.  B  .  .         .  P  .  .         P  B  P  .         .  B  .  P
.  .  .  .         .  .  .  .         .  P  .  .         .  .  .  .



   t=4                t=5                t=6
.  .  .  .         .  .  .  .         .  P  .  .
.  .  .  S         .  P  .  .         .  .  .  .
.  P  .  .         P  B  P  S         .  B  .  P
.  .  .  .         .  P  .  .         .  .  .  S

Input format
Line 1: Three space separated integers N, M and K, describing the number of rows and columns in the grid and the number of Blasters, respectively.


Lines 2 to K+1: These lines describe the K blasters. Each line has four space separated integers. The first two integers on the line denote the row and column where the Blaster is located, the third integer is its starting time, and the fourth integer is its frequency.


Output format
The first line of output must either consist of the word YES, if Spaceman Spiff can reach his ship safely, or the word NO, if he cannot do so. If the output on the first line is YES then the second line should contain a single integer giving the least time, in seconds, that it takes him to reach his ship safely.


Sample Input 1
4 4 1
3 2 1 3

Sample Output 1
YES
6

Sample Input 2
5 5 2
5 1 1 2
4 4 1 2

Sample Output 2
YES
8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;
#define int int64_t

class Blaster
{
public:
	int x;
	int y;
	int t;
	int f;
};

int n, m, k;


int grid[2501][2501] = { 0, };
Blaster blaster[2501];

bool solve(int i, int j)
{
	if (j == m)
		return 0;

	if (i == n && j == m - 1)
		return 1;

	if (i == n)
		return 0;

	if (grid[i][j] == -1)
		return 0;

	if (grid[i][j] == 1)
		return 1;

	bool r, d;
	r = solve(i, j + 1);
	d = solve(i + 1, j);

	if (r || d)
		return grid[i][j] = 1;

	grid[i][j] = -1;
	return 0;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		cin
			>> blaster[i].x
			>> blaster[i].y
			>> blaster[i].t
			>> blaster[i].f;

		blaster[i].x--;
		blaster[i].y--;

		grid[blaster[i].x][blaster[i].y] = -1;
	}

	int dx[4] = { 0, 0,  1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < k; ++i)
	{
		for (int l = 0; l < 4; ++l)
		{
			int cnt = 1;
			int x = blaster[i].x;
			int y = blaster[i].y;
			int t = blaster[i].t;
			int f = blaster[i].f;

			while (1)
			{
				int x1 = (x + (cnt * dx[l]));
				int y1 = (y + (cnt * dy[l]));

				if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
					break;

				int time = (x1 + y1);
				int dist = (abs(y1 - y) + abs(x1 - x));

				if ((time >= t) && (time - (t + dist)) % f == 0 && (time - ((t + dist)) >= f))
					grid[x1][y1] = -1;

				cnt++;
			}
		}
	}

	bool ans = solve(0, 0);

	cout << (ans ? "YES" : "NO") << endl;

	if (ans)
		cout << (n + m - 2) << endl;

	return 0;
}
