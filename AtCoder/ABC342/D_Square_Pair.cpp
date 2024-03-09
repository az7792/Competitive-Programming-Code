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
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> f(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
            continue;
        map<int, int> s;
        ll x = a[i];
        for (int j = 2; j <= x / j; ++j)
        {
            while (x % j == 0)
            {
                s[j]++;
                x /= j;
            }
        }
        if (x > 1)
            s[x]++;
        ll tmp = 1;
        for (auto &[x, y] : s)
            if (y % 2 == 1)
                tmp *= x;
        f[i] = tmp;
        mp[tmp]++;
    }
    ll ans = 0;
    ll z = 0;
    for (int i = 0; i < n; ++i)
    {
        // f[i]
        if (a[i] == 0)
        {
            ans += n - 1 - z;
            z++;
        }
        else
        {
            ans += max(0ll, mp[f[i]] - 1);
            mp[f[i]]--;
        }
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
