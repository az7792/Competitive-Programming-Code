#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
vector<pair<ll, ll>> a;
void solve()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    a.resize(n, {0, 0});
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        mp[a[i].first] += a[i].second;
    }
    vector<pair<ll, ll>> tmp;
    for (auto v : mp)
        tmp.push_back(v);
    ll ans = min(tmp[0].first - 1, m);
    ll sum = 0;
    for (int i = 1; i < tmp.size(); ++i)
    {
        sum += tmp[i - 1].second;
        ll r = tmp[i].first - 1;
        ll x = m + sum;
        x = min(x, r);
        if (x < tmp[i - 1].first)
            continue;
        ans = max(ans, x);
    }
    sum += tmp.back().second;
    ll x = m + sum;
    if (x >= tmp.back().first)
    {
        ans = max(ans, x);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
