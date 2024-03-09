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
    ll n, c, d, tmp;
    cin >> n >> c >> d;
    set<ll> a;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        mp[tmp]++;
        a.emplace(tmp);
    }
    ll ans = 0;
    for (auto &[x, y] : mp)
    {
        ans += (y - 1) * c;
    }
    ll ct = 1, num = 1e18;
    for (auto v : a)
    {
        ll t = (v - ct) * d + (a.size() - ct) * c;
        num = min(num, t);
        ct++;
    }
    num = min(num, (ll)a.size() * c + d);
    cout << ans + num << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}