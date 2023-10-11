/*
https://www.codechef.com/ZCOPRAC/problems/ZCO22002?tab=submissions
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int freq[50][50]; 
int max_freq[50];
bool orig_b[131073][19];
bool found[131073]; 
vector<int> res;
vector<vector<int>> arr;

void solve(int n, int m)
{
    
    for(int i = 0; i < 50;++i)
        for(int j = 0; j < 50;++j)
            freq[i][j] = 0;
    
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            freq[j][arr[i][j]]++;
            
    for(int i = 0; i < 50;++i)
        max_freq[i] = -1;
    
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<=n; ++j)
        {
            if(freq[i][j]== (m/2))
                max_freq[i] = j;
        }
    }
    
    for(int i=0; i<n; ++i)
    {
        if(max_freq[i]== -1)
        {
            cout << "0" << endl << endl; 
            return;
        }
    }
    
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            orig_b[i][j] = (arr[i][j] != max_freq[j]);
            
    for(int i = 0; i < m;++i)
        found[i] = 0;
     
    for(int i=0; i<m; ++i)
    {
        int pos_i =0;
        for(int j=0; j<n; ++j)
            pos_i += ((pow(2,j)) * orig_b[i][j]);
        found[pos_i] = 1;
    }
    
    bool is_ok = 1;
    for(int i=0; i<m; i++)
        if(found[i] == 0) 
            is_ok = 0;
            
    if(is_ok == 0)
    {
        cout<<"0\n\n";
        return;
    }
    
    res.clear();
    int ans = 0;
    for(int i=0; i < m; ++i)
    {
        bool can_be = 1;
        for(int j=0; j < n; ++j)
            if(freq[j][arr[i][j]] != (m / 2))
               can_be = 0;
        if(can_be) 
        {
            res.push_back(i);
            ans++;
        }
    }
    
    cout << ans << endl;
    for(int i = 0; i < ans;++i) 
        cout << res[i] << " "; 
    
    cout << endl;
}
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			vector<int> tmp(17);
			for (int j = 0; j < n; ++j)
				cin >> tmp[j];

			arr.push_back(tmp);
		}
        
        solve(n,m);
        arr.clear();
	}
}
