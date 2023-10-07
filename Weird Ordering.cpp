/*
https://www.codechef.com/ZCOPRAC/problems/ZCO20001?tab=statement
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;

#define int unsigned long long
vector<int> ans1, ans2;

vector<int> order(vector<int> arr, int i) {
	if (arr.size() <= 1)
		return arr;

	vector<int> r, l;

	int n = arr.size();

	for (int j = 0; j < n; ++j)
	{
		if ((arr[j] % (int)pow(2, i + 1)) < pow(2, i))
			l.push_back(arr[j]);
		else
			r.push_back(arr[j]);
	}

	l = order(l, i + 1);
	r = order(r, i + 1);

	vector<int> c;

	for (int j = 0; j < l.size(); ++j)
		c.push_back(l[j]);
	for (int j = 0; j < r.size(); ++j)
		c.push_back(r[j]);

	return c;
}

vector<int> solve(int p)
{
	p = pow(2, p);
	vector<int> ans2;

	for (int i = 0; i < p; ++i)
	{
		int l = 0, u = p, idx = i;
		while (idx != 0)
		{
			if (idx % 2)
				l += ((u - l) / 2);
			else
				u -= ((u - l) / 2);

			idx /= 2;
		}

		ans2.push_back(l);
	}

	return ans2;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	int t;
	cin >> t;
	while (t--)
	{
		int p;
		cin >> p;
		vector<int> arr;

		for (int i = 0; i < pow(2,p); ++i)
			arr.push_back(i);

		ans1 = order(arr, 0);
		ans2 = solve(p);

		if (ans1 == ans2)
			cout << "AC" << endl;
		else
			cout << "WA" << endl;
	}
#else
	int t;
	cin >> t;
	while (t--)
	{
		int idx, p;
		cin >> p >> idx;

		int l = 0, u = pow(2, p);

		while (idx != 0)
		{
			if (idx % 2)
				l += ((u - l) / 2);
			else
				u -= ((u - l) / 2);

			idx /= 2;
		}

		cout << l << endl;
	}
#endif
}
