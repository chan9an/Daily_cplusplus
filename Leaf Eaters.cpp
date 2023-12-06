#include <bits/stdc++.h>
using namespace std;

inline long long lcm (long long a, long long b)
{
    return (a*b) / gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long number_of_leaves, number_of_caterpillars, temp;
    cin >> number_of_leaves >> number_of_caterpillars;
    vector<long long> caterpillar_length;
    for (long long i = 0; i < number_of_caterpillars; i++)
    {
        cin >> temp;
        caterpillar_length.push_back(temp);
        if (temp == 1)
        {
            cout << 0;
            return 0;
        }
    }
    long long lowest_divisor;
    if (number_of_caterpillars < 2)
    {
        lowest_divisor = number_of_leaves;
    }
    else
    {
        lowest_divisor = lcm(caterpillar_length[0], caterpillar_length[1]);
        for (int i = 2; i < number_of_caterpillars; i++)
        {
            lowest_divisor = lcm (caterpillar_length[i], lowest_divisor);
            if (lowest_divisor >= number_of_leaves)
            {
                break;
            }
        }
        lowest_divisor = min (lowest_divisor, number_of_leaves);
    }
    bool is_leaf_damaged[lowest_divisor+1] = {false};
    long long count = lowest_divisor;
    for (int i = 0; i < number_of_caterpillars; i++)
    {
        for (int j = 1; j <= lowest_divisor; j += caterpillar_length[i])
        {
            if (!is_leaf_damaged[j])
            {
                is_leaf_damaged[j] = true;
                count--;
            }
        }
    }
    long long answer = 0, it = 0;
    while (it < number_of_leaves)
    {
        answer += count;
        it += lowest_divisor;
    }
    long long it2 = lowest_divisor;
    while (it > number_of_leaves)
    {
        if (is_leaf_damaged[it2] == false)
        {
            answer--;
        }
        it--;
        it2--;
    }
    cout << answer;
    return 0;
}
