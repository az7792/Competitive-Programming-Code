#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(2 * n + 1), sum(2 * n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = n + 1; i <= 2 * n; ++i)
        a[i] = a[i - n];
    for (int i = 1; i <= 2 * n; ++i)
    {
        sum[i] += sum[i - 1] + a[i];
        sum[i] %= m;
    }
    map<ll, ll> mp;
    for (int i = 1; i <= n - 1; ++i)
    {
        mp[sum[i]]++;
    }
    ll ans = 0, st = 0;
    ans += mp[0];
    for (int i = 2; i <= n; ++i)
    {
        mp[(a[i - 1] + st) % m]--;
        st += a[i - 1];
        st %= m;
        mp[(sum[i + n - 2] - sum[i - 1] + st) % m]++;
        ans += mp[st];
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
