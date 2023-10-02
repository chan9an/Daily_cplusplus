/*
Zonal Computing Olympiad 2015, 29 Nov 2014
We have a rectangular region that is 
100000
100000 units along the 
�
X-axis and 
500
500 units along the 
�
Y-axis.

We assume that the origin 
(
0
,
0
)
(0,0) is at the bottom-left corner of this region, so that the top-left corner is at 
(
0
,
500
)
(0,500), the bottom-right at 
(
100000
,
0
)
(100000,0) and the top-right corner at 
(
100000
,
500
)
(100000,500). We are also given the coordinates of a set of 
�
N points inside this region. The points have only integer coordinates and do not appear along the 
�
X-axis or 
�
Y-axis.

We would like to draw a rectangle, with its base on the 
�
X-axis, of maximum area within the region such that it does not contain any of the 
�
N points in its interior. More specifically, the points may appear on the boundary but cannot be properly inside the rectangle.

For example, if there are 
5
5 points : 
(
1
,
4
)
,
(
2
,
3
)
,
(
3
,
2
)
,
(
5
,
1
)
(1,4),(2,3),(3,2),(5,1) and 
(
5
,
2
)
(5,2). Then the rectangle whose bottom-left and top-right corners are given by 
(
0
,
0
)
(0,0) and 
(
2
,
3
)
(2,3) is a possibility and its area is 
6
6. Another possibility is the rectangle with bottom-left and top-right corners at 
(
3
,
0
)
(3,0) and 
(
5
,
500
)
(5,500) with area 
1000
1000. The rectangle with bottom-left at 
(
2
,
3
)
(2,3) and top-right at 
(
100000
,
500
)
(100000,500) is not valid since its base does not lie on the 
�
X-axis. The largest rectangle that meets the requirements in this case is the one with its bottom-left corner at 
(
5
,
0
)
(5,0) and top-right at 
(
100000
,
500
)
(100000,500) with area 
49997500
49997500.

Your program should take a description of the 
�
N points and output the size of the maximum rectangle satisfying the above property that can be drawn within the 
100000
×
500
100000×500 region.

Input format
The first line contains a single integer 
�
N, giving the number of points marked in the region.

This is followed by 
�
N lines, each containing two integers separated by a space describing the coordinates of one point.

Output format
Output a single integer giving the area of the largest rectangle that may be drawn with its base on the 
�
X-axis and which does not contain any of the given 
�
N points in its interior.

Test data
In both subtasks, the 
�
X-coordinate of each of the 
�
N points is in the range 
1
1 to 
99999
99999 inclusive, and the 
�
Y-coordinate of each of the 
�
N points is in the range 
1
1 to 
499
499 inclusive.

Subtask 
1
1 (
40
40 marks) 
:
1
≤
�
≤
5000
:1≤N≤5000
Subtask 
2
2 (
60
60 marks) 
:
1
≤
�
≤
100000
:1≤N≤100000
Sample Input
5
1 4 
2 3
3 2
5 1
5 2

Sample Output
49997500

accepted
Accepted
572
total-Submissions
Submissions
3032
accuracy
Accuracy
22.46

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i].first>>v[i].second;
    }
    stack<pair<int,int>> stk; // stores points which are less then curr height
    vector<int> lb(n), rb(n);
    sort(v.begin(), v.end()); // sorted based on x-axis
/*  lb stores how much we can strech v[i] from left
    rb stores how much we can strech v[i] from right
    v  = {{1,4}, {2,3}, {3,2}, {5,1}, {5,2}}
    lb = { 0   ,  0   ,  0   ,  0   ,  5   }
    rb = { 2   ,  3   ,  5   ,  1e5 ,  1e5 }
    the last elem's lb is 5 cuz in the rb u can strech it till 1e5 but if lb[n-1] < 5 then that 5,1 point will come inside the rectangle
    if u cant understand then dont worry when u see the rest of the code u will understand    */
    for(int i = 0; i < n; i++){
        while(!stk.empty() && stk.top().second >= v[i].second){ // popping the elems which are greater or equal than curr elem (v[i].second) cuz v[i].second is gonna be the rectangle height
            stk.pop();
        }
        if(stk.empty()){ // if theres no greater elem then v[i].second(curr elem) then we can stretch the left side of the rectangle till 0
            lb[i] = 0;
        }else{ // if there is a element then we can stretch the rectangle to the nearest point
            lb[i] = stk.top().first;
        }
        stk.push(v[i]);
    }
    while(!stk.empty()){ // reuse stk to compute rb vecter, u can make another stack if u want to
        stk.pop();
    }
    for(int i = n-1; i > 0; i--){ // stk stores elems smaller then curr elem so when starting i=0 we have to store the points which are greater then curr elem so i started i from n-1
        while(!stk.empty() && stk.top().second >= v[i].second){  // popping the elems which are greater or equal than curr elem (v[i].second) cuz v[i].second is gonna be the rectangle height
            stk.pop();
        }
        if(stk.empty()){ // if theres no greater elem then v[i].second(curr elem) then we can stretch the right side of the rectangle till 100000
            rb[i] = 1e5;
        }else{ // if there is a element then we can stretch the rectangle to the nearest point
            rb[i] = stk.top().first;
        }
        stk.push(v[i]);
    }
/*  doing max of:
    rectangle starting from x-axis 0 till x-axis of the first point(it can be on its boundary) with height 500(y-axis 500)
    rectangle starting from the last point x-axis and ending at 100000(in the question it's written that x-axis will be 100000 long) with height 500
    v is sorted to there will be no points inside the rectangle which im making
    in further computations if currArea wasn't greater then the rectangle which im making rn then this will be a back up option   */
    int maxArea = max(v[0].first, 100000-v[n-1].first)*500;
    
    for(int i = 0; i < n; i++){
        int len = rb[i]-lb[i]; // how many units in the x-axis v[i](its still ok if the point comes on its boundary) can stretch
        maxArea = max(maxArea, len*v[i].second); // v[i].second is the height of the rectangle which im making rn
    }
    for(int i = 1; i < n; i++){ // started i from 1 cuz doing v[i-1].first in the loop
        maxArea = max(maxArea, (v[i].first-v[i-1].first)*500); // making a rectangle in between the points with height 500
    }
    cout<<maxArea<<'\n';
    return 0;
}
