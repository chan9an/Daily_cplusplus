//https://www.codechef.com/INOIPRAC/problems/TINOI17B?tab=statement
#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

int n, S_0;
vector<lli> S, E;
vector<vector<lli>> dp;

lli sumcube(lli n)
{
    lli sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum * sum * sum;
}

lli maxE(int city, int t)
{   
    if (city >= n) return 0;
    
    if (dp[city][t] != -1) return dp[city][t];
    
    dp[city][t] = max(maxE(city + 1, t + 1), maxE(city + 1, t) + S[t] * E[city]);
    return dp[city][t];
}

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
 
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
 
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x)
            return pos;
 
        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
 
        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

int binarySearch(int arr[], int, int, int);
  
// Returns position of first occurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
        return 0;
  
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
  
    //  Call binary search for the found range.
    return binarySearch(arr, i/2, 
                            min(i, n-1), x);
}
  
// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
    }
  
    // We reach here when element is not present
    // in array
    return -1;
}

int main() {
    cin >> n >> S_0;
    
    // Calculate strength after t trainings
    S.resize(n + 1);
    S[0] = S_0;
    for (int i = 1; i <= n; i++)
    {
        S[i] = S[i - 1] + sumcube(S[i - 1]);
    }
    
    // Experience of each gym
    E.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> E[i];
    }
    
    // Memoization of function
    dp.resize(5001, vector<lli>(5001, -1));
    
    // Solve
    cout << maxE(0, 0) << "\n";
}
