#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;

#define int int64_t

int ans[100001];

vector<pair<int, int>> v1, v2;

bool comp1(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

bool comp2(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first)
		return p1.second > p2.second;
	return p1.first > p2.first;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			ans[i] = 0;

		v1.clear();
		v2.clear();

		for (int i = 0; i < n; ++i)
		{
			int val1, val2;
			cin >> val1 >> val2;

			v1.push_back(make_pair(val1, i));
			v2.push_back(make_pair(val2, i));
		}

		sort(v1.begin(), v1.end(), comp1);//sort in ascending order
		sort(v2.begin(), v2.end(), comp2);//sort in descending order

		for (int i = 0; i < v1.size(); ++i)
		{
			ans[v1[i].second] += (n - i - 1);//for lower bound will consider all elements greater
			ans[v2[i].second] += (n - i - 1);//for upper bound will consider all elements smaller (as it is sorted it descending order)
			//if lower bounds equal or upper bounds equal sort will consider draws as it also considers the second element(which is unique)
		}

		for (int i = 0; i < n; ++i)
			cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}
