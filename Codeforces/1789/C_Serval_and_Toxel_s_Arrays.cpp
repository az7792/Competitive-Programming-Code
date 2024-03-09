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
map<ll, ll> mp;
vector<pll> num(MAX, {0, 0}); // 当前位置正在统计的数字,开始统计的轮数
vector<ll> G(MAX, 0);
void solve()
{
    mp.clear();
    ll n, m, p, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> G[i];
        num[i].first = G[i];
        num[i].second = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> p >> v;
        if (num[p].first != v)
        {
            mp[num[p].first] += (i - num[p].second);
            num[p].first = v;
            num[p].second = i;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        mp[num[i].first] += (m + 1 - num[i].second);
    }
    ll ans = 0, ans1 = 0;
    for (auto &[x, y] : mp)
    {
        ans += (y) * (y - 1) / 2;
        ans1 += (m + 1 - y) * y * 2;
    }
    cout << ans + ans1 / 2 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/