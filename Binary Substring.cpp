#include <bits/stdc++.h>
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
using namespace std;

// function to findParent permutation
long long permutation(long long n, long long r)
{
    long long p = 1, mod = 1e9 + 7;
    // npk == n*(n-1)*(n-2).........(n-r+1);
    for (long long i = 0; i < r; i++)
    {
        p = ((p % mod) * (n - i)) % mod;
    }
    return (p + mod) % mod;
}

class DisjointSet
{
    vector<long long> rank, parent;

public:
    DisjointSet(long long n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (long long i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    // path compression
    long long findParent(long long node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void UnionByRank(long long u, long long v)
    {
        long long pu = findParent(u);
        long long pv = findParent(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class SegmentTree
{
    vector<int> tree;

public:
    SegmentTree(int n)
    {
        tree.resize(4 * n);
    }
    // creating the tree
    void build(int index, int low, int high, vector<int> &v)
    {
        if (low == high)
        {
            tree[index] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, v);
        build(2 * index + 2, mid + 1, high, v);
        // here we are trying to store the value in our segment tree
        // we can change it according to our question i.adj to store maximum or minimum or sum
        tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
        // for sum
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    int query(int index, int low, int high, int l, int r, vector<int> &v)
    {
        // if completely lying in the range then return it
        if (low >= l && high <= r)
        {
            return tree[index];
        }
        // if not lying in the range
        // we can change the retur statement here according to our query i.adj for min we will use INT_MAX and for sum return 0
        if (low > r or high < l)
            return INT_MAX;
        int mid = (low + high) / 2;
        int left = query(2 * index + 1, low, mid, l, r, v);
        int right = query(2 * index + 2, mid + 1, high, l, r, v);
        return max(left, right);
    }
    // function to update the segment tree
    void pointUpdate(int index, int low, int high, int l, int h, int value)
    {
        if (low == high)
        {
            tree[low] += value;
            return;
        }
        else
        {
            int mid = (low + high) / 2;
            pointUpdate(2 * index + 1, low, mid, l, h, value);
            pointUpdate(2 * index + 2, mid + 1, high, l, h, value);
            // updating the roots
            tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
        }
    }
};
int gcd(int v, int v2)
{
    if (v2 == 0)
        return v;
    else
        return gcd(v2, v % v2);
}
int mod = 1e9 + 7;
long long BinaryMultiplication(long long v, long long v2)
{
    if (v2 == 0)
        return 1;
    long long ans = BinaryMultiplication(v, v2 / 2);
    if (v2 % 2)
        return ans * ans * v;
    else
        return (ans * ans);
}

void ChiknaBhai()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<int, int> stringCategories;
    for (int i = 0; i < n; i += 2) // n/2 ~ n
    {
        if (s[i] == '0' && s[i + 1] == '0')
            stringCategories[0]++; // 1
        else if (s[i] == '1' && s[i + 1] == '1')
            stringCategories[1]++; // 1
        else if (s[i] == '0' && s[i + 1] == '1')
            stringCategories[2]++; // 1
        else
            stringCategories[3]++; // 1
    }
    /// 10 first, then 00s, then 01, then 11s, then 10 left over (ideal)

    // lets put all 00s and 11s
    int maxLength = 2 * stringCategories[0] + 2 * stringCategories[1];
    if (stringCategories[2] > 0) // add that 01 in between 00s and 11s
        maxLength += 2;
    if (stringCategories[3] > 0) // add that 10 at the start
    {
        maxLength++;
        stringCategories[3]--;
        if (stringCategories[3] > 0) // if possible now add 10 at end too
        {
            maxLength++;
        }
    }
    cout << maxLength << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        ChiknaBhai();
    }
}
