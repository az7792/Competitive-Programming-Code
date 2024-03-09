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
void solve()
{
    ll n, c, s;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s >> c;
        mp[s] += c;
    }
    ll ans = 0;
    for (auto &[x, y] : mp)
    {
        ans += y % 2;
        mp[2 * x] += y / 2;
    }
    cout << ans;
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