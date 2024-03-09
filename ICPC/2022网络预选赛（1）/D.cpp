#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<ll> Min;
ll tmp;
int n, m;
void dfs(int p, int num, ll now)
{
    if (num == m)
    {
        now = now << (m + 2);
        Min.push_back(now | tmp);
        return;
    }
    if (p > n)
        return;
    if (n - (p-1) + num < m)
        return;
    dfs(p + 1, num, now);
    dfs(p + 1, num + 1, now | (1ll << (p - 1)));
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    int p = lower_bound(all(Min), l) - Min.begin();
    if (Min[p] > r)
        cout << -1 << endl;
    else
        cout << Min[p] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int i = 1; i <= 15; ++i)
    {
        tmp = (1ll << i);
        n = 30 - i - 1;
        m = i - 1;
        dfs(1, 0, 0);
    }
    sort(all(Min));
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}