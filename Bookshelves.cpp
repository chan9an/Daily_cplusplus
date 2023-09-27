/*Uncle Shiva is an avid collector of books. In his study he has two long shelves with N books in each of them. He has invited the artist Lavanya to decorate his study.
Lavanya feels that the arrangement of books in the two shelves is not aesthetic. She has come up with a measure for the elegance of the two shelves called Skew. The Skew of the two bookshelves is defined to be the sum of the heights of the tallest books in each of the two shelves.

Lavanya recommends rearranging the books between the two shelves so that the Skew is as small as possible. On the other hand, Uncle Shiva prides himself as a balanced personality and always wants the two shelves to have an equal number of books, N in each.

Lavanya is an artist, she merely recommends what needs to be done, leaving the actual rearranging to Uncle Shiva. Uncle Shiva on the other hand is lazy and would like to do very little work. As a compromise, Uncle Shiva is willing to exchange books between the two shelves K times and would like to do these exchanges cleverly so as to make the Skew as small as possible (via K swaps).

For example, suppose each shelf contained 5 books, where the heights of the books on the first shelf are 3, 5, 2, 7 and 1, and the heights of the books on the second shelf are 14, 2, 3, 10 and 4. The Skew of this arrangement is 7 + 14 = 21. If K = 1, i.e., Uncle Shiva is willing to exchange only one book between the two, he can swap the book with height 2 in shelf 1 with the book with height 14 in shelf 2 and this will increase the Skew to 24! On the other hand if he swaps the book with height 7 in the first shelf with the book with height 3 in the second shelf then the resulting arrangement has a Skew of 5 + 14 = 19. You can verify that if K = 1 then this is the smallest Skew that can be achieved. So for this case the answer is 19.

Your task is to write a program that takes as input, N - the number of books in each shelf, K - the number of swaps that Uncle Shiva is willing to do, and the heights of the books on the two shelves, and computes the smallest Skew value that can be achieved through at most K swaps of books between the two shelves.
Input format
There is only one line, which contains ((2 × N) + 2) space separated integers.
The first two integers are N and K.
The next N integers, give the heights of the N books in the first book shelf.
The last N integers, give the heights of the N books in the second book shelf.
Output format
A single line with a single integer giving the minimum Skew that can be achieved via at most K swaps between the two bookshelves
Test data
You may assume that the heights of all the books lie in the range between 0 and 108, both inclusive and that 1 ≤ N ≤ 105. Note that there may be more than one book with the same height on a bookshelf.

Subtask 1 (30 Marks) You may assume that K = 1.
Subtask 2 (70 Marks) 0 ≤ K ≤ N.

Sample Input
5 1 3 5 2 7 1 14 2 3 10 4
Sample Output
19
Explanation
N = 5, K = 1
The first book shelf contains books with heights {3, 5, 2, 7, 1}.
The second book shelf contains books with heights {14, 2, 3, 10, 4}
This is same as the example explained above, and so the answer is 19.*/

#include <bits/stdc++.h>
using namespace std;

int minSkew(vector<int> a,vector<int> b,int k){
    int n = a.size();
    for(int i=0;i<k;i++){
        if(a[n-1] > b[0]){
        swap(a[n-1],b[0]);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
}
return a[n-1] + b[n-1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> v1(n),v2(n);
	for(int i=0;i<n;i++){
	    cin>>v1[i];
	}
	for(int i=0;i<n;i++){
	    cin>>v2[i];
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int ans1=minSkew(v1,v2,k);
	int ans2=minSkew(v2,v1,k);
	
	cout<<min(ans1,ans2);
	return 0;
}
