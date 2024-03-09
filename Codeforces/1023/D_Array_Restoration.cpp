#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, q, fq = 0, fz = 0;
vector<int> G(MAX, 0), D(MAX, 1e9);
map<int, pii> mp;
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int v)
{
    if (v == 0)
        v = 1e9;        
    G[x] = v;
    while (x <= n)
    {
        D[x] = min(D[x], v);
        x += lowbit(x);
    }
}
int query(int l, int r)
{
    if (l > r)
        return 1e9;
    int res = 1e9;
    while (l <= r)
    {
        res = min(res, G[r]);
        r--;
        for (; r - lowbit(r) >= l; r -= lowbit(r))
            res = min(res, D[r]);
    }
    return res;
}
void solve()
{
    cin >> n >> q;
    for (int i = 1, tmp; i <= n; ++i)
    {
        cin >> tmp;
        if (tmp == q)
            fq = 1;
        if (tmp == 0)
            fz = 1;
        add(i, tmp);
    }
    for (int i = 1; i <= n; ++i)
        if (G[i] != 1e9 && mp[G[i]].first == 0)
            mp[G[i]].first = i, mp[G[i]].second = 0;
    for (int i = n; i >= 1; --i)
        if (G[i] != 1e9 && mp[G[i]].second == 0)
            mp[G[i]].second = i;
    for (auto [x, y] : mp)
    {
        auto [l, r] = y;
        int Min = query(l + 1, r - 1);
        if (Min < x)
        {
            cout << "NO";
            return;
        }
    }
    if (!fq && !fz)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    bool f = fq ? 1 : 0;
    if (!fq)
    {
        for (int i = 1; i <= n; ++i)
            if (G[i] == 1e9)
            {
                G[i] = q;
                break;
            }
    }
    for(int i=1;i<=n;++i)
    {
        if(G[i]!=1e9)
            {
                G[0]=G[i];
                break;
            }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (G[i] == 1e9)
            G[i] = G[i - 1];
        cout << G[i] << ' ';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/