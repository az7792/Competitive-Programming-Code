#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define FAST                         \
    {                                \
        ios::sync_with_stdio(false); \
        cin.tie(nullptr);            \
        cout.tie(nullptr);           \
    }
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct DSU
{
    vector<int> fa;
    DSU(int n) // 最大编号
    {
        fa.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            fa[i] = i;
    }
    int Find(int p)
    {
        if (p != fa[p])
            fa[p] = Find(fa[p]);
        return fa[p];
    }
    void Union(int a, int b)
    {
        int FA = Find(a), FB = Find(b);
        fa[FA] = FB;
    }

    bool isUnion(int a, int b)
    {
        int FA = Find(a), FB = Find(b);
        return FA == FB;
    }
};

int main()
{
    DSU dsu(5);
    dsu.Union(1, 2);
    dsu.Union(1, 3);
    dsu.Union(4, 5);

    cout << dsu.isUnion(3, 2);
    cout << dsu.isUnion(5, 4);
    return 0;
}
