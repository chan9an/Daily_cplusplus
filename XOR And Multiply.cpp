// !!!--JAI MAA SARASWATI--!!!
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int mod1 = 998244353; // it is a prime number which is also equals to (119*(2^23) + 1)!
const int m1 = 1e6 + 1;
int se[m1];

int floorSqrt(int x) // to calculate the floor square root of a number in log(x) time complexity!
{
    if (x == 0 || x == 1)
        return x;

    int start = 1, end = x / 2, ans;
    while (start <= end)
    {
        long double mid = (start + end) / 2;

        long double sqr = mid * mid;
        if (sqr == x)
            return mid;

        if (sqr <= x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

bool isPerf(int a) // to check whether a number is perfect number or not!
{
    if (a <= 1)
        return true;

    int low = 1, high = a;
    while (low <= high)
    {
        long double mid = low + (high - low) / 2;
        long double squ = mid * mid;
        if (squ == a)
            return true;
        else if (squ < a)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

void sieve() // to make the table of first prime divisior of different number,it is also used to check whether a number is prime number
             //  or not because first prime divisor of a prime number is number itself (obviously)!
{
    for (int i = 1; i < m1; i++)
    {
        se[i] = i;
    }
    for (int i = 4; i < m1; i += 2)
    {
        se[i] = 2;
    }
    for (int i = 3; i * i < m1; i++)
    {
        if (se[i] == i)
        {
            for (int j = i * i; j < m1; j += i)
            {
                if (se[j] == j)
                {
                    se[j] = i;
                }
            }
        }
    }
}

void add_divs(int x, map<int, int> &divs) // to get the all prime divisors of a number!
{
    int i = 2;
    while (i * i <= x)
    {
        while (x % i == 0)
        {
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if (x > 1)
        divs[x]++;
}

int fem(int a, int b) // to calculate the fast exponential of a to b!
{
    int t = 1;
    while (b > 0)
    {
        if (b % 2)
        {
            t = (t * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return t % mod;
}

int fact(int a) // to calculate the factorial of a number!
{
    int res = 1;
    for (int i = 2; i <= a; i++)
    {
        res = (res * i) % mod;
    }
    return res % mod;
}

int nCr(int n, int r) // to calculate the required combination of a number!
{
    return fact(n) / (fact(r) * fact(n - r));
}

int mm(int a, int b) // to calculate the modulo of the product of the two numbers!
{
    return ((a % mod) * (b % mod)) % mod;
}

int no_of_digit(int a, int b)
{
    return ((int)(b * log10(a)) + 1);
}

int lsb(int n)
{
    return log2(n & -n);
}

int msb(int n)
{
    return (63 - __builtin_clzll(n));
}

int nsb(int n)
{
    return __builtin_popcount(n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = msb(n);
        map<long long, long long> mp;
        for (int i = 0; i <= m; i++)
        {
            if (n & (1LL << i))
                mp[i]++;
        }
        int a = 0, b = 0;
        for (auto &it : mp)
        {
            a |= (1LL << (it.first));
            b |= (1LL << (it.first));
        }
        for (auto &it : mp)
        {
            a |= (1LL << (it.first + m + 1));
        }
        cout << b << " " << a << endl;
    }
    return 0;
}
