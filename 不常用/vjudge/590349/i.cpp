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
    int n;
    cin >> n;
    map<int, ll> mp;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0, N = 0;
    for (auto &[x, y] : mp)
        N += y * (y - 1) / 2;
    for (int i = 0; i < n; ++i)
    {
        N -= mp[a[i]] - 1;
        ll sum = n - 1 - i;
        mp[a[i]]--;
        sum -= mp[a[i]];
        ans += (sum) * (sum - 1) / 2 - N + (mp[a[i]] * (mp[a[i]] - 1) / 2);
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