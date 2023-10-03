/*
n this problem you are given a sequence of 
�
N positive integers 
�
[
1
]
,
�
[
2
]
,
…
,
�
[
�
]
S[1],S[2],…,S[N]. In addition you are given an integer 
�
T, and your aim is to find the number of quadruples 
(
�
,
�
,
�
,
�
)
(i,j,k,l), such that 
1
≤
�
<
�
<
�
<
�
≤
�
1≤i<j<k<l≤N, and 
�
[
�
]
+
�
[
�
]
+
�
[
�
]
+
�
[
�
]
=
�
S[i]+S[j]+S[k]+S[l]=T. That is, the number of ways of picking four numbers from the sequence summing up to 
�
T.

Constraints:
For all test cases,

1
≤
�
≤
5000
1≤N≤5000
1
≤
�
≤
1
0
6
1≤T≤10 
6
 
1
≤
�
[
�
]
≤
1
0
9
1≤S[i]≤10 
9
 , for all 
�
i.
Subtask 
1
:
10
%
1:10%

It is guaranteed that 
�
≤
50
N≤50.

Subtask 
2
:
50
%
2:50%

It is guaranteed that 
�
≤
300
N≤300.

Subtask 
3
:
40
%
3:40%

No additional guarantees.

Input Format:
There is only one line of input with 
�
+
2
N+2 space separated integers. The first two integers are 
�
N and 
�
T. The next 
�
N integers are 
�
[
1
]
,
�
[
2
]
,
…
,
�
[
�
]
S[1],S[2],…,S[N].

Output Format:
A single integer which is the number of valid quadruples.

Sample Input 1:
6 20 3 1 1 2 5 10

Sample Output 1:
1

Explanation 1:
The quadruple 
(
1
,
4
,
5
,
6
)
(1,4,5,6) is valid because 
�
[
1
]
+
�
[
4
]
+
�
[
5
]
+
�
[
6
]
=
3
+
2
+
5
+
10
=
20
S[1]+S[4]+S[5]+S[6]=3+2+5+10=20. You can check that no other quadruple is valid and hence the answer is 
1
1.

Sample Input 2:
6 13 1 2 3 4 5 4

Sample Output 2:
3
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
vector<int> arr;
vector<int> sums;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int n, t;
	cin >> n >> t;

	arr.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (n < 4) { cout << "0" << endl; return 0; }

	sort(arr.begin(), arr.end());
	sums.resize(t + 1);

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; ((j < n) && (t >= arr[i] + arr[j])); ++j)
			ans += sums[t - arr[i] - arr[j]];

		for (int j = 0; ((j < i) && (arr[i] + arr[j] <= t)); ++j)
			sums[arr[i] + arr[j]]++;
	}

	cout << ans << endl;
}
