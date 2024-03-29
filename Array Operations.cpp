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

// to check if it is valid to take h as answer
bool valid(vector<int> v, int h, int k)
{
    int cntK = 0, req = h, canBecome = 0;
    multiset<int> opp;

    for (int i = 0; i < v.size(); i++)
    {
        int val = v[i];
        if (val < h)
        {
            while (val % k == 0)
                val /= k, cntK++;
            if (val * k >= h)
                canBecome++;
        }
        else
        {
            while (val % k == 0 && val / k >= h)
                val /= k, cntK++;

            int extra = 0;
            while (val % k == 0)
                val /= k, extra++;
            if (extra >= 2)
                opp.insert(extra);

            req--;
        }
    }

    int mn = min(cntK, canBecome);
    req -= mn;
    cntK -= mn;
    canBecome -= mn;

    while (canBecome >= 2 && !opp.empty())
    {
        int last = *opp.rbegin();
        opp.erase(opp.find(last));
        cntK += last;
        req++;

        int mn = min(cntK, canBecome);
        req -= mn;
        cntK -= mn;
        canBecome -= mn;
    }

    return req <= 0;
}
void ChiknaBhai()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (valid(v, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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
