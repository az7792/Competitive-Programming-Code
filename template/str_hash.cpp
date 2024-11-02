#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Hash
{

    ull m1 = 1e9 + 7, m2 = 998244353;
    ull X1 = 13331, X2 = 133331;
    vector<ull> h1, h2;
    vector<ull> x1, x2;

    int n;

    Hash(string str)
    {
        n = str.size();
        Hash_(str, h1, x1, m1, X1);
        Hash_(str, h2, x2, m2, X2);
    }

    pair<ull, ull> getHash(int L, int R) // hash[L,R]
    {
        ull hash1 = getHash(L, R, h1, x1, m1);
        ull hash2 = getHash(L, R, h2, x2, m2);
        return pair<ull, ull>(hash1, hash2);
    }

    void Hash_(string str, vector<ull> &h, vector<ull> &x, ull m, ull X)
    {
        h.clear(), x.clear();
        h.resize(str.size());
        x.resize(str.size());
        h[0] = str[0], x[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            h[i] = (h[i - 1] * X + str[i]) % m;
            x[i] = (x[i - 1] * X) % m;
        }
    }
    ull getHash(int L, int R, vector<ull> &h, vector<ull> &x, ull m)
    {
        if (L > R)
            return 0;
        return (h[R] - (L > 0 ? (h[L - 1] * x[R - L + 1]) % m : 0) + m) % m;
    }
};