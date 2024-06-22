#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> num(MAX, 0); // i点的值
vector<int> Max(MAX, 0); // i点维护区间的最值
int N;
int lowbit(int x)
{
    return x & (-x);
}
int q(int l, int r) // max[l,r]
{
    int res = 0;
    while (r >= l)
    {
        if (r - lowbit(r) >= l)
        {
            res = max(res, Max[r]);
            r -= lowbit(r);
        }
        else
        {
            res = max(res, num[r]);
            r--;
        }
    }
    return res;
}
void add(int p, int x) // updata( num[p] -> x)
{
    num[p] = x;
    //更新当前结点维护的区间
    Max[p] = x;
    for (int j = 1; j < lowbit(p); j <<= 1)
        Max[p] = max(Max[p], Max[p - j]);
    //更新包含当前结点的区间
    int tmp = p;
    p += lowbit(p);
    for (; p <= N; p += lowbit(p))
    {
        Max[p] = max(Max[p], Max[tmp]);
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll Min = n - 1 + abs(a[n] - a[1]);
    vector<int> G;
    G.push_back(0);
    for (int i = 1; i <= n; ++i)
        if ((a[1] <= a[i] && a[i] <= a[n]) || (a[1] >= a[i] && a[i] >= a[n]))
            G.push_back(a[i]);
    N = max(G[1], G.back());
    vector<int> dp(G.size(), 0);
    for (int i = dp.size() - 2; i >= 1; --i)
    {
        dp[i] = 1 + q(min(G[i], G.back()), max(G[i], G.back()));
        num[G[i]] = max(num[G[i]], dp[i]);
        add(G[i], num[G[i]]);
    }
    cout << Min << " " << dp[1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
