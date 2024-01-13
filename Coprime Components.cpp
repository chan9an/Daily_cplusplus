#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

class DisjointSet {
private:
    vector<int> lab;

public:
    DisjointSet(int n = 0) {
        if (n > 0) lab.assign(n + 7, -1);
    }

    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

    bool join(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }

    int getSize(int x) {
        return -lab[find(x)];
    }
};

void answer(int x) {
    cout << x << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   1000100
#define BIG_GRAPH   9090

bool notPrime[MAX], notPrimeProduct[MAX];
int primeDivProduct[MAX];
vector<int> primeDiv[MAX];

void eratosthene(void) {
    REP(i, 2) notPrime[i] = true;
    for (int i = 2; 1LL * i * i < MAX; i++) if (!notPrime[i]) {
        for (int j = i * i; j < MAX; j += i * i) notPrimeProduct[j] = true;
        for (int j = i * i; j < MAX; j += i) notPrime[j] = true;
    }
    REP(i, MAX) primeDivProduct[i] = 1;
    FOR(i, 2, MAX - 1) if (!notPrime[i])
        for (int j = i; j < MAX; j += i) {
            if (!notPrimeProduct[j]) primeDiv[j].push_back(i);
            primeDivProduct[j] *= i;
        }
}

int numValue, values[MAX], numMultiple[MAX], numSeparate;
int cache[MAX];

void init(void) {
    scanf("%d", &numValue);
    FOR(i, 1, numValue) {
        scanf("%d", &values[i]);
        if (values[i] == 1) answer(1);
        values[i] = primeDivProduct[values[i]];
    }
}

bool haveCoprime(int value) {
    if (cache[value] >= 0) return cache[value];

    int numCandidate = 0;
    vector<int> &divs = primeDiv[value];
    REP(mask, MASK(divs.size())) {
        int prod = 1;
        REP(i, divs.size()) if (BIT(mask, i)) prod *= divs[i];
        if (__builtin_popcount(mask) % 2 == 0) numCandidate += numMultiple[prod];
        else numCandidate -= numMultiple[prod];
    }
    cache[value] = numCandidate > 0 ? 1 : 0;
    return cache[value];
}

void removeSeparate(void) {
    memset(cache, -1, sizeof cache);
    vector<int> haveEdge;
    FOR(i, 1, numValue) numMultiple[values[i]]++;
    FOR(i, 1, MAX - 1) if (!notPrimeProduct[i])
        for (int j = 2 * i; j < MAX; j += i) numMultiple[i] += numMultiple[j];

    FOR(i, 1, numValue) {
        if (haveCoprime(values[i])) haveEdge.push_back(values[i]);
        else numSeparate++;
    }

    memset(cache, 0, sizeof cache);
    FORE(it, haveEdge) cache[*it] = true;
    FOR(i, 2, MAX - 1) if (cache[i])
        for (int j = 2 * i; j < MAX; j += i) cache[j] = false;
    numValue = 0;
    FOR(i, 2, MAX - 1) if (cache[i]) values[++numValue] = i;
}

bool isCoprime(int x, int y) {
    if (primeDiv[x].size() < primeDiv[y].size()) {
        FORE(it, primeDiv[x]) if (y % *it == 0) return false;
        return true;
    } else {
        FORE(it, primeDiv[y]) if (x % *it == 0) return false;
        return true;
    }
    assert(false);
}

void process(void) {
    if (numValue > BIG_GRAPH) answer(1 + numSeparate);
    DisjointSet dsu(numValue);
    int numComp = numValue;
    FOR(i, 1, numValue) FOR(j, i + 1, numValue)
        if (dsu.find(i) != dsu.find(j) && isCoprime(values[i], values[j])) {
            assert(dsu.join(i, j));
            numComp--;
        }
    answer(numComp + numSeparate);
}

int main(void) {
    eratosthene();
    init();
    removeSeparate();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
