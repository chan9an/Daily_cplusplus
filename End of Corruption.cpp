#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin >> n >> m;
	int ctz[n]; // array of citizens
	int v = 0; // v=visit
	for(int i = 0; i < n+m; i++)
	{
	    int a;
	    cin >> a;
	    if(a == -1)
	    {
	        v++;
	        int lrg = 0;
	        for(int k = 0; k < i-v+1; k++)// index of largest integer in array
	        {
	            if(ctz[k] > ctz[lrg])
	            {
	                lrg = k;
	            }
	        }
	        cout <<  ctz[lrg] << endl; // execution of richest citizen
	        ctz[lrg] = 0;
	    }
	    else
	    {
	        ctz[i-v] = a; //appending a citizen to array
	    }
	    /*
	    for(int y = 0; y < n; y++)
	    {
	        cout << ctz[y] << endl;
	    }
	    cout << endl;
	    */
	}
	return 0;
}
