#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 4e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(all(a));
    ll ans = 0;
    for (auto &[x, y] : mp)
    {
        if (y >= 2)
        {
            ans += ((ll)y * (y - 1) / 2) * (lower_bound(all(a), x) - a.begin());
        }
        if (y >= 3)
        {
            ans += (ll)y * (y - 1) * (y - 2) / 6;
        }
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
