#include <iostream>
#include <string.h>
using namespace std;
#define f(a, b) for(int a = 0; a < b; a++)
#define fast_io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

bool isPalindrome(string word)
{
    bool pld = true;
    int l = word.length();
    for(int k = 0; k < l / 2; k++)
    {
        if(word[k] != word[l-k-1])
        {
            pld = false;
            break;
        }
    }
    return pld;
}

string substring(string word,int s, int e)
{
    char sub[e-s+2];
    for(int i = 0; i <= e-s; i++)
    {
        sub[i] = word[s+i];
    }
    sub[e-s+1] = '\0';
    return string(sub);
}

int main() {
    fast_io;
	string word;
	int n;
	
	cin >> n;
	cin >> word;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            string curr = substring(word,j,n-i+j-1);
            if(isPalindrome(curr))
            {
                cout << curr.size() << endl;
                cout << curr;
                return 0;
            }
        }
    }

	//return 0;
	
}
