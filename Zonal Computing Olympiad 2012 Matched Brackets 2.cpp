/*
Zonal Computing Olympiad 2012, 26 Nov 2011

We consider sequences of opening and closing brackets with two types of brackets, () and []. A bracket sequence is well-bracketed if we can pair up each opening bracket with a matching closing bracket in the usual sense. For instance, the sequences (), [] ([]) and []([]) are well-bracketed, while (, ()], (], )( and [(]) are not well-bracketed. In the last case, each opening bracket has a matching closing bracket and vice versa, but the intervals spanned by the different types of brackets intersect each other instead of being contained one within the other.


The alternating depth of a well-bracketed sequence tells us the maximum number of times we switch between the two types of brackets when we have inner matched brackets enclosed within outer matched brackets. For instance, the alternating depth of (), [[[]]] and ()[][] is 1, the alternating depth of [()] and ()([]) is 2, the alternating depth of ([()]) and [()][(([]))] is 3, and so on.


Given a well-bracketed sequence, we are interested in computing three quantities.

The alternating depth of the sequence.
The maximum number of symbols between any pair of matched brackets of the type ( and ), including both the outer brackets.
The maximum number of symbols between any pair of matched brackets of the type [ and ], including both the outer brackets.

For instance, the alternating depth of (([]))[[[()]]] is 2, the maximum number of symbols between a matched pair () is 6 and the maximum number of symbols between a matched pair [] is 8.
Input format
The input consists of two lines. The first line is a single integer N, the length of the bracket sequence. Positions in the sequence are numbered 1,2,…,N. The second line is a sequence of N space-separated integers that encode the bracket expression as follows: 1 denotes an opening bracket (, 2 denotes a closing bracket ), 3 denotes an opening bracket [ and 4 denotes a closing bracket ]. Nothing other than 1, 2, 3 or 4 appears in the second line of input and the corresponding expression is guaranteed to be well-bracketed.


Output format
Your program should print 3 space-separated integers in a line, denoting the three quantities asked for in the following order: alternating depth, length of the maximum sequence between matching () brackets and length of the maximum sequence between matching [] brackets.


Testdata
You may assume that 2 ≤ N ≤ 105. In 30% of the test cases, 2 ≤ N ≤ 103.
Subtask 1 (30 marks)
Subtask 2 (70 marks)

Sample Input
14
1 1 3 4 2 2 3 3 3 1 2 4 4 4

Sample Output
2 6 8
*/



#include <bits/stdc++.h>
using namespace std;
//More over only alternatingDepth is difficult part of this question

/* Very IMP Note 
u might think that the alternating brackets have to be continuous but
thats completely wrong cuz depth DOESNT mean that it has to be continuous */
void helper(string &str)
{
    int n=str.length();
    stack<int> st;
    st.push(0);

    int maxDepth=INT_MIN,currDepth=1,simpleBracket=0,squareBracket=0;
    char removedBracketInverse;
    for(int i=1;i<n;i++)
    {
        if(str[i]=='(' || str[i]=='[')
        {
            if(st.empty()||str[i]!=str[st.top()])  currDepth++;
            maxDepth=max(maxDepth,currDepth);
            
            st.push(i);
        }
        else
        {
            if(str[i]==')')
            {
                simpleBracket=max(simpleBracket,i-st.top()+1);
            }
            else
            {
                squareBracket=max(squareBracket,i-st.top()+1);
            }
            st.pop();
            removedBracketInverse=(str[i]==')'?'(':'[');
            if(st.empty()||removedBracketInverse!=str[st.top()])  currDepth--;
        }
    }
    cout<<maxDepth<<" "<<simpleBracket<<" "<<squareBracket<<endl;
}
int main() 
{
	int n,x;
	cin>>n;
	string pat="";
	for(int i=0;i<n;i++)
	{
	    cin>>x;
	    switch (x)
	    {
	        case 1:
	            pat+="(";
	            break;
	        case 2:
	            pat+=")";
	            break;
	        case 3:
	            pat+="[";
	            break;
            case 4:
                pat+="]";
                break;
	    }
	}
	helper(pat);
	return 0;
}
