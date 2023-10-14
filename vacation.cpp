/*https://www.codechef.com/ZCOPRAC/problems/ZCO22001?tab=submissions*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;

#define int int64_t

vector<vector<int>> arr;


int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	
		int n, m;
		cin >> n >> m;

		arr.resize(n + 1);
		for (int i = 0; i < n; ++i)
		{
			arr[i].resize(m + 1);
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[i][j];
				//replace with zeros till now
				int curr = 0;

				if (i > 0)
					curr += arr[i - 1][j];//left submatrix
				if (j > 0)
					curr += arr[i][j - 1];//right submatrix
				if (i > 0 && j > 0)
					curr -= arr[i - 1][j - 1];//fix zeros counted twice

				arr[i][j] = (arr[i][j] == 0)/*check if current is 0*/ + curr/*number of zeros in the other portion of the matrix*/;
			}
		}
		
		int q;
		cin >> q;
		while (q--)
		{
			//for each query
			//take in coordinates
			int a, b, c, d;
			cin >> a >> b >> c >> d;

			a--, b--, c--, d--;
			int ans = arr[c][d];
			
			if (b != 0)
				ans -= arr[c][b - 1];
			
			if (a != 0)
				ans -= arr[a - 1][d];

			if (a != 0 && b != 0)
				ans += arr[a - 1][b - 1];

			cout << (ans == 0) << endl;
		}

	return 0;
}
